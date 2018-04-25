#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //Database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Database/noMisteaks.sqlite");

    if(db.open())
        qDebug() << "Database connected\n";
    else
        qDebug() << "Database NOT connected\n";

    QSqlQuery count(db);
    QVector<QString> names;
    int num = 0;

    //select in the order they are given
    count.prepare("SELECT teamName FROM stadiums ORDER BY stadiumID");

    //Counting total
    if(count.exec()) {
        while(count.next()) {
            num++;
        }
    }
    totalData = num;

    InitializeMatrix(num);

//    graph.DisplayMatrix();

    ui->TripAmount->setRange(1, 99);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeMatrix(int num) {
    Stadium* newStadium = new Stadium();
    graph.SetTotalVertices(num);

    //Initializing matrix
    QSqlQuery qMatrix(db);
    QSqlRecord record;
    qMatrix.prepare("SELECT * FROM edges ORDER BY stadiumID");
    qMatrix.exec();
    qMatrix.first();

    record = qMatrix.record();
    int** matrix = new int*[num];

    for(int i = 0; i < num; i++) {
        matrix[i] = new int[record.count()-1];
    }

    int i = 0;
    while(qMatrix.isValid()) {
        for(int j = 0; j < record.count(); j++) {
            matrix[i][j] = qMatrix.record().value(j+1).toInt();
        }
        qMatrix.next();
        i++;
    }
    graph.SetMatrix(matrix);


    //Initializing stadiums
    QSqlQuery query(db);
    query.prepare("SELECT * FROM stadiums ORDER BY stadiumID");

    if(query.exec()) {
        while(query.next()) {
            newStadium->SetID(query.value(0).toInt());
            newStadium->SetTeamName(query.value(1).toString());
            newStadium->SetStadiumName(query.value(2).toString());
            newStadium->SetCapacity(query.value(3).toDouble());
            newStadium->SetLocation(query.value(4).toString());
            newStadium->SetConference(query.value(5).toString());
            newStadium->SetSurfaceType(query.value(6).toString());
            newStadium->SetRoofType(query.value(7).toString());
            newStadium->SetStarPlayer(query.value(8).toString());
            newStadium->SetInitRevenue(query.value(9).toDouble());

            graph.CreateVert(*newStadium);
            newStadium = new Stadium();
        }
    }

    //Initializing souvenirs
    QSqlQuery qSouv(db);
    qSouv.prepare("SELECT * FROM souvenirs ORDER BY stadiumID");

    int j = 0;
    if(qSouv.exec()) {
        while(qSouv.next()) {
            Souvenirs temp;
            for (int a = 1; a < qSouv.record().count(); a++) {
                if (qSouv.record().value(a).toDouble() != -1) {
                    temp.SetAll(qSouv.record().fieldName(a), qSouv.record().value(a).toDouble());
                    graph.vertList[j].name.AddSouvenir(temp);
                }
            }
            j++;
        }
    }
}


//H O M E   P A G E
void MainWindow::on_H_AdminB_clicked() {
    SecDialog secdialog;    //Dialog box

    //PROCESSING - opens dialog box that asks user to enter password
    secdialog.setModal(true);
    secdialog.exec();
    QString myPass;
    myPass = "password";

    //PROCESSING - if password is correct, sets index to admin page and
    //                  fills combo box
    if(secdialog.isVisible() == false && secdialog.get_text() == myPass) {
        ui->stackedWidget->setCurrentIndex(2);
        ui->stackedWidget->hide();
        ui->stackedWidget->show();
    }
}

void MainWindow::on_H_NextB_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Exit_clicked() {
    QApplication::quit();
}


//T R I P   P A G E
void MainWindow::on_T_BackB_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_T_DefaultB_clicked() {
    curID = 0;
    graph.SetTotalMil(0);
    Graph<Stadium,int>::Vertex tList[graph.GetTotalV()];

    for (int i = 0; i < graph.GetTotalV(); i++)
        tList[i] = graph.vertList[i];

    graph.Dijkstra(15);

    for (int i = 0; i < graph.GetTotalV(); i++)
       graph.vertList[i] = tList[i];

    Stadium* temp = graph.GetSortedVertices();
    curTemp = temp;
    curCount = graph.GetSortCount();
    listRemove = 0;

    UpdateTripTable(temp, curCount);
    ui->stackedWidget->setCurrentIndex(3);
}

    void MainWindow::on_D_NextB_clicked() {
        curID++;
        if (curID < curCount) {
            UpdateTripTable(curTemp, curCount);
        }
        else {
            ui->GrandTotal->setText(QString::number(graph.GetGrandTotal()));
            UpdateTripFinTable();
            UpdateTotRevTable();
            ui->stackedWidget->setCurrentIndex(13);
        }
    }

    void MainWindow::on_D_BuyB_clicked() {
        if (col > 1) {
            souvBoughtTeam << curTemp[curID].GetTeamName();
            souvBoughtName << curTemp[curID].GetSouvenirName(col-2);
            double temp = 0.00;
            for (int i = 0; i < ui->TripAmount->value(); i++) {
                temp += curTemp[curID].GetSouvenirPrice(col-2);
            }
            souvBoughtPrice << temp;
            souvBoughtAmount << ui->TripAmount->value();
            int tempID = 0;

            for (int i = 0; i < graph.GetTotalV(); i++) {
                if (curTemp[curID].GetID() == graph.vertList[i].name.GetID()) {
                    graph.vertList[i].name.SetTotalRevenue(temp);
                    tempID = i;
                }
            }

            QSqlQuery query(db);
            query.exec("UPDATE stadiums SET revenue='" + QString::number(graph.vertList[tempID].name.GetTotalRevenue()) + "' WHERE stadiumID=" + QString::number(tempID));
            
            ui->TripAmount->setValue(1);
            ui->D_Error->setText("Souvenir added!");
        }
        else if (col == -1)
            ui->D_Error->setText("ERROR - Select a souvenir!");
        else
            ui->D_Error->setText("ERROR - Cannot add ID or Team Name!");
    }

    void MainWindow::on_D_FinB_clicked() {
        ui->GrandTotal->setText(QString::number(graph.GetGrandTotal()));
        UpdateTripFinTable();
        UpdateTotRevTable();
        ui->stackedWidget->setCurrentIndex(13);
    }

    void MainWindow::on_DF_BackB_clicked() {
        souvBoughtTeam.clear();
        souvBoughtName.clear();
        souvBoughtPrice.clear();
        souvBoughtAmount.clear();
        ui->stackedWidget->setCurrentIndex(1);
    }

void MainWindow::on_T_CustomB_clicked() {
    curCount = 0;
    row = -1;
    for (int i = 0; i < graph.GetTotalV(); i++) {
        souvBoughtTeam << graph.vertList[i].name.GetStadiumName();
        teamName2 << graph.vertList[i].name.GetTeamName();
    }
    UpdateCTripTable();
    UpdateCYourTable();
    ui->stackedWidget->setCurrentIndex(4);
}

    void MainWindow::on_C_AddB_clicked() {
        if (curCount >= 32) {
            //qDebug() << "ERROR - No more stadiums left to add!";
        }
        else if (row != -1) {
            curCount++;
            souvBoughtName << souvBoughtTeam.at(row);
            souvBoughtTeam.removeAt(row);
            teamName1 << teamName2.at(row);
            teamName2.removeAt(row);
            UpdateCTripTable();
            UpdateCYourTable();
        }
        else {
            //qDebug() << "ERROR - Please select a stadium first!";
        }
    }

    void MainWindow::on_C_StartB_clicked() {
        if (!souvBoughtName.isEmpty()) {
            curID = 0;
            curCount = 0;
            graph.SetTotalMil(0);

            Stadium* temp = graph.GetCountedVertices(souvBoughtName.size());
            for (int j = 0; j < souvBoughtName.size(); j++) {
                for (int i = 0; i < graph.GetTotalV(); i++) {
                    if (teamName1.at(j) == graph.vertList[i].name.GetTeamName()) {
                        temp[curCount] = graph.vertList[i].name;
                        if (curCount != 0) {
                            graph.Dijkstra(temp[curCount-1].GetID(), i);
                        }
                        curCount++;
                    }
                }
            }

            curTemp = temp;
            listRemove = 0;
            souvBoughtName.clear();
            souvBoughtTeam.clear();
            souvBoughtAmount.clear();
            teamName1.clear();
            teamName2.clear();

            UpdateTripTable(temp, curCount);

            ui->stackedWidget->setCurrentIndex(3);
        }
        else {
            //qDebug() << "ERROR - Must choose at least one stadium!";
        }
    }

void MainWindow::on_T_MSTB_clicked() {
    graph.SetTotalMil(0);
    ui->MSTList->setText(graph.PrimMST());
    ui->M_Miles->setText(QString::number(graph.GetMatrixResult()));
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_T_ViewB_clicked() {
    UpdateViewTable();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_T_BFSB_clicked() {
    graph.SetTotalMil(0);
    ui->BFSList->setText(graph.BFS(15));
    ui->BFS_Miles->setText(QString::number(graph.GetMatrixResult()));
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_T_DFSB_clicked() {
    graph.SetTotalMil(0);
    ui->DFSList->setText(graph.DFS(15));
    ui->DFS_Miles->setText(QString::number(graph.GetMatrixResult()));
    ui->stackedWidget->setCurrentIndex(11);
}

    //Trips/View/MST
    void MainWindow::on_D_BackB_clicked() {
        souvBoughtTeam.clear();
        souvBoughtName.clear();
        souvBoughtPrice.clear();
        souvBoughtAmount.clear();
        ui->stackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_C_BackB_clicked() {
        souvBoughtName.clear();
        souvBoughtTeam.clear();
        souvBoughtAmount.clear();
        teamName1.clear();
        teamName2.clear();
        ui->stackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_M_BackB_clicked() {
        graph.SetMatrixResult(0);
        ui->stackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_V_BackB_clicked() {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_BFS_BackB_clicked() {
        graph.SetMatrixResult(0);
        ui->stackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_DFS_BackB_clicked() {
        graph.SetMatrixResult(0);
        ui->stackedWidget->setCurrentIndex(1);
    }


//A D M I N   P A G E
void MainWindow::on_A_AddB_clicked() {
    nID = 0;
    nTeam = "";
    nStadium = "";
    nCapacity = 0.00;
    nLocation = "";
    nConference = "";
    nSurface = "";
    nRoof = "";
    nStar = "";
    UpdateAddStadTable();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_A_BackB_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_A_StadiumsB_clicked() {
    row = -1;
    UpdateModStadTable();
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_A_SouvenirsB_clicked() {
    row = -1;
    curTeam = 0;
    UpdateModSouvTable();
    UpdateModSouvList();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_A_AddSouvB_clicked() {
    curCount = -1;
    row = -1;
    souvTemp.SetAll("", 0.00);
    UpdateAddSouvTable();
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_A_EdgesB_clicked() {
    row = -1;
    UpdateEdgesTable();
    ui->stackedWidget->setCurrentIndex(14);
}

    //Admin Options
        //Add Stadium
        void MainWindow::on_ADD_BackB_clicked() {
            ui->stackedWidget->setCurrentIndex(2);
        }

        void MainWindow::on_ADD_AddB_clicked() {
            Stadium* addStadium = new Stadium(nID, nTeam, nStadium, nCapacity, nLocation,
                                              nConference, nSurface, nRoof, nStar, 0.00);
            //Setting souviners
            QSqlQuery qSouv(db);
            qSouv.prepare("INSERT INTO stadiums (stadiumID, teamName, stadiumName, capacity, location, conference, surfaceType, roofType, starName, revenue) "
                          "VALUES (:id, :name, :stad, :cap, :loc, :con, :sur, :roof, :star, :rev)");
            qSouv.bindValue(":id", nID);
            qSouv.bindValue(":name", nTeam);
            qSouv.bindValue(":stad", nStadium);
            qSouv.bindValue(":cap", nCapacity);
            qSouv.bindValue(":loc", nLocation);
            qSouv.bindValue(":con", nConference);
            qSouv.bindValue(":sur", nSurface);
            qSouv.bindValue(":roof", nRoof);
            qSouv.bindValue(":star", nStar);
            qSouv.bindValue(":rev", 0);
            qSouv.exec();

            qSouv.prepare("SELECT * FROM souvenirs ORDER BY stadiumID");


            if(qSouv.exec() && qSouv.next()) {
                Souvenirs temp;

                temp.SetAll("Signed Helmets", 72.99);
                addStadium->AddSouvenir(temp);
                temp.SetAll("Autographed Football", 49.39);
                addStadium->AddSouvenir(temp);
                temp.SetAll("Team Pennant", 17.99);
                addStadium->AddSouvenir(temp);
                temp.SetAll("Team Picture", 19.99);
                addStadium->AddSouvenir(temp);
                temp.SetAll("Team Jersey", 185.99);
                addStadium->AddSouvenir(temp);
            }

            qSouv.exec("INSERT INTO souvenirs (stadiumID) VALUES ('" + QString::number(nID) + "')");

            //Setting new vertices
            Graph<Stadium,int>::Vertex* temp = graph.vertList;
            int** tempMatrix = graph.GetMatrix();

            graph.SetTotalVertices(graph.GetTotalV()+1);

            graph.SetVertList(temp);
            graph.SetNewMatrix(tempMatrix);
            graph.CreateVert(*addStadium, nID);

            qSouv.exec("ALTER TABLE edges ADD '" + QString::number(graph.GetTotalV()-1) + "' INT DEFAULT 0");
            qSouv.exec("INSERT INTO edges (stadiumID) VALUES ('" + QString::number(graph.GetTotalV()-1) + "')");

            UpdateAddEdgeTable();
            UpdateAddWeightTable();
            curTeam = 0;
            curWeight = 0.00;
            col = -2;
            nCapacity = -1;

            ui->stackedWidget->setCurrentIndex(12);
        }

        void MainWindow::on_ADD2_AddB_clicked() {
//            qDebug() << curTeam << " - " << graph.GetTotalV()-1 << ": " << curWeight;
            if (curWeight == 0)
                ui->ADD2_Error->setText("ERROR - Value cannot be a 0!");
            else if (col >= 0) {
                QSqlQuery query(db);
                int** temp = graph.GetMatrix();

                //Changing Edge from selected team to new team
                temp[curTeam][graph.GetTotalV()-1] = curWeight;
                query.exec("UPDATE edges SET '" + QString::number(curTeam) + "'='" + QString::number(curWeight) + "' WHERE stadiumID=" + QString::number(graph.GetTotalV()-1));

                //Changing Edge from new team to selected team
                temp[graph.GetTotalV()-1][curTeam] = curWeight;
                query.exec("UPDATE edges SET '" + QString::number(graph.GetTotalV()-1) + "'='" + QString::number(curWeight) + "' WHERE stadiumID=" + QString::number(curTeam));

                graph.SetMatrix(temp);
                ui->ADD2_Error->setText("Edge Added!");
                col = -1;
                nCapacity = 0;
            }
            else if (col == -2) {
                ui->ADD2_Error->setText("ERROR - Select a stadium!");
            }
//            graph.DisplayMatrix();
        }

        void MainWindow::on_ADD2_BackB_clicked() {
            if (nCapacity != -1)
                ui->stackedWidget->setCurrentIndex(2);
            else
                ui->ADD2_Error->setText("ERROR - Must add at least one edge!");
        }

        //M O D   E D G E S
         void MainWindow::on_ME_BackB_clicked() {
             ui->stackedWidget->setCurrentIndex(2);
         }

         //A D D  S O U V E N I R S
          void MainWindow::on_AS_BackB_clicked() {
              souvTemp.SetAll("", 0.00);
              ui->stackedWidget->setCurrentIndex(2);
          }

          void MainWindow::on_AS_AddB_clicked() {
              if (row == 0 && curCount == 0) {
                   ui->AS_Error->setText("Souvenir Added!");
                   graph.vertList[curTeam].name.AddSouvenir(souvTemp);

                   QSqlQuery query(db);
                   query.exec("ALTER TABLE souvenirs ADD '" + souvTemp.GetName() + "' DOUBLE DEFAULT -1");
                   query.exec("UPDATE souvenirs SET '" + souvTemp.GetName() + "'='" + QString::number(souvTemp.GetPrice()) + "' WHERE stadiumID=" + QString::number(curTeam));
              }
              else if (curCount == -1){
                   ui->AS_Error->setText("ERROR - Select a stadium!");
              }
              else if (row == -1){
                   ui->AS_Error->setText("ERROR - Value not an numerical value (ex. 10.21)!");
                   //ui->AddSouvTable->setItem(0, 1, new QTableWidgetItem());
              }
          }

    void MainWindow::on_MSTA_BackB_clicked() {
        ui->stackedWidget->setCurrentIndex(2);
    }

    void MainWindow::on_MSOU_BackB_clicked() {
        curTeam = 0;
        ui->stackedWidget->setCurrentIndex(2);
    }

    void MainWindow::on_MSOU_DeleteB_clicked() {
        if (graph.vertList[curTeam].name.GetSouvTotal() <= 0) {
            ui->MSOU_Error->setText("ERROR - No more souvenirs to delete!");
        }
        else if (col != -1 || col < graph.vertList[curTeam].name.GetSouvTotal()) {
            curCount = 0;
            disconnect(ui->ModSouvTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedSouv(const QModelIndex&)));

            QSqlQuery query(db);
            query.exec("UPDATE souvenirs SET '" + graph.vertList[curTeam].name.GetSouvenirName(col) + "'='" + QString::number(-1) + "' WHERE stadiumID=" + QString::number(curTeam));

            graph.vertList[curTeam].name.RemoveSouvenir(col);
            if (graph.vertList[curTeam].name.GetSouvTotal() == 0)
                graph.vertList[curTeam].name.ClearSouvenirs();  

            UpdateModSouvTable();
        }
        else
            ui->MSOU_Error->setText("ERROR - Select a souvenir!");
    }


void MainWindow::UpdateViewTable() {
    totalCapacity = 0;
    ui->viewAllTable->setRowCount(graph.GetTotalV());
    ui->viewAllTable->setColumnCount(9);
    ui->viewAllTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->viewAllTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Team"));
    ui->viewAllTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Stadium"));
    ui->viewAllTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Capacity"));
    ui->viewAllTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Location"));
    ui->viewAllTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Conference"));
    ui->viewAllTable->setHorizontalHeaderItem(6, new QTableWidgetItem("SurfaceType"));
    ui->viewAllTable->setHorizontalHeaderItem(7, new QTableWidgetItem("RoofType"));
    ui->viewAllTable->setHorizontalHeaderItem(8, new QTableWidgetItem("Star"));

    for(int i = 0; i < graph.GetTotalV(); i++) {
        ui->viewAllTable->setItem(i, 0, new QTableWidgetItem(QString::number(graph.vertList[i].name.GetID())));
        ui->viewAllTable->setItem(i, 1, new QTableWidgetItem(graph.vertList[i].name.GetTeamName()));
        ui->viewAllTable->setItem(i, 2, new QTableWidgetItem(graph.vertList[i].name.GetStadiumName()));
        ui->viewAllTable->setItem(i, 3, new QTableWidgetItem(QString::number(graph.vertList[i].name.GetCapacity())));
        ui->viewAllTable->setItem(i, 4, new QTableWidgetItem(graph.vertList[i].name.GetLocation()));
        ui->viewAllTable->setItem(i, 5, new QTableWidgetItem(graph.vertList[i].name.GetConference()));
        ui->viewAllTable->setItem(i, 6, new QTableWidgetItem(graph.vertList[i].name.GetSurfaceType()));
        ui->viewAllTable->setItem(i, 7, new QTableWidgetItem(graph.vertList[i].name.GetRoofType()));
        ui->viewAllTable->setItem(i, 8, new QTableWidgetItem(graph.vertList[i].name.GetStarPlayer()));
        ui->viewAllTable->setVerticalHeaderItem(i, new QTableWidgetItem(""));
        totalCapacity += graph.vertList[i].name.GetCapacity();
    }
    ui->totCapacity->setText(QString::number(totalCapacity));
    ui->viewAllTable->resizeColumnsToContents();
    ui->V_Error->setText("");
    connect(ui->viewAllTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedView(const QModelIndex&)));
}

void MainWindow::UpdateModStadTable() {
    ui->ModStadTable->setRowCount(graph.GetTotalV());
    ui->ModStadTable->setColumnCount(9);
    ui->ModStadTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->ModStadTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Team"));
    ui->ModStadTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Stadium"));
    ui->ModStadTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Capacity"));
    ui->ModStadTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Location"));
    ui->ModStadTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Conference"));
    ui->ModStadTable->setHorizontalHeaderItem(6, new QTableWidgetItem("SurfaceType"));
    ui->ModStadTable->setHorizontalHeaderItem(7, new QTableWidgetItem("RoofType"));
    ui->ModStadTable->setHorizontalHeaderItem(8, new QTableWidgetItem("Star"));

    for(int i = 0; i < graph.GetTotalV(); i++) {
        ui->ModStadTable->setItem(i, 0, new QTableWidgetItem(QString::number(graph.vertList[i].name.GetID())));
        ui->ModStadTable->setItem(i, 1, new QTableWidgetItem(graph.vertList[i].name.GetTeamName()));
        ui->ModStadTable->setItem(i, 2, new QTableWidgetItem(graph.vertList[i].name.GetStadiumName()));
        ui->ModStadTable->setItem(i, 3, new QTableWidgetItem(QString::number(graph.vertList[i].name.GetCapacity())));
        ui->ModStadTable->setItem(i, 4, new QTableWidgetItem(graph.vertList[i].name.GetLocation()));
        ui->ModStadTable->setItem(i, 5, new QTableWidgetItem(graph.vertList[i].name.GetConference()));
        ui->ModStadTable->setItem(i, 6, new QTableWidgetItem(graph.vertList[i].name.GetSurfaceType()));
        ui->ModStadTable->setItem(i, 7, new QTableWidgetItem(graph.vertList[i].name.GetRoofType()));
        ui->ModStadTable->setItem(i, 8, new QTableWidgetItem(graph.vertList[i].name.GetStarPlayer()));
        ui->ModStadTable->setVerticalHeaderItem(i, new QTableWidgetItem(""));
    }
    ui->viewAllTable->resizeColumnsToContents();
    connect(ui->ModStadTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedStad(const QModelIndex&)));
}

void MainWindow::UpdateModSouvTable() {
    ui->ModSouvTable->setRowCount(1);
    ui->ModSouvTable->setColumnCount(graph.vertList[curTeam].name.GetSouvTotal());
    ui->ModSouvTable->setVerticalHeaderItem(0, new QTableWidgetItem("Price"));

    if (graph.vertList[curTeam].name.GetSouvTotal() != 0) {
        for (int i = 0; i < graph.vertList[curTeam].name.GetSouvTotal(); i++) {
            ui->ModSouvTable->setHorizontalHeaderItem(i, new QTableWidgetItem(graph.vertList[curTeam].name.GetSouvenirName(i)));
            ui->ModSouvTable->setItem(0, i, new QTableWidgetItem(QString::number(graph.vertList[curTeam].name.GetSouvenirPrice(i))));
        }

        ui->ModSouvTable->resizeColumnsToContents();
        connect(ui->ModSouvTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedSouv(const QModelIndex&)));
    }
    else {
        ui->ModSouvTable->setHorizontalHeaderItem(0, new QTableWidgetItem("No Souvenirs To Display!"));
        ui->ModSouvTable->setItem(0, 0, new QTableWidgetItem(""));
        ui->ModSouvTable->resizeColumnsToContents();
    }
}

void MainWindow::UpdateModSouvList() {
    ui->ModSouvList->setRowCount(graph.GetTotalV());
    ui->ModSouvList->setColumnCount(1);
    ui->ModSouvList->setHorizontalHeaderItem(0, new QTableWidgetItem("Team"));

    for (int i = 0; i < graph.GetTotalV(); i++) {
        ui->ModSouvList->setItem(i, 0, new QTableWidgetItem(graph.vertList[i].name.GetTeamName()));
        ui->ModSouvList->setVerticalHeaderItem(i, new QTableWidgetItem(""));
    }
    ui->ModSouvList->resizeColumnsToContents();
//    ui->AS_Error->setText("");
}

void MainWindow::UpdateAddStadTable() {
    ui->AddStadTable->setRowCount(1);
    ui->AddStadTable->setColumnCount(9);
    ui->AddStadTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->AddStadTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Team Name"));
    ui->AddStadTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Stadium Name"));
    ui->AddStadTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Capacity"));
    ui->AddStadTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Location"));
    ui->AddStadTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Conference"));
    ui->AddStadTable->setHorizontalHeaderItem(6, new QTableWidgetItem("Surface Type"));
    ui->AddStadTable->setHorizontalHeaderItem(7, new QTableWidgetItem("Roof Type"));
    ui->AddStadTable->setHorizontalHeaderItem(8, new QTableWidgetItem("Star Player"));

    ui->AddStadTable->setItem(0, 0, new QTableWidgetItem(QString::number(graph.GetTotalV())));

    ui->AddStadTable->setVerticalHeaderItem(0, new QTableWidgetItem(""));
    ui->AddStadTable->resizeColumnsToContents();
    nID = graph.GetTotalV();

    ui->ADD_Error->setText("");
    connect(ui->AddStadTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedAdd(const QModelIndex&)));
}

void MainWindow::UpdateAddEdgeTable() {
    ui->AddEdgeTable->setRowCount(graph.GetTotalV()-1);
    ui->AddEdgeTable->setColumnCount(1);
    ui->AddEdgeTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Locations"));

    for(int i = 0; i < graph.GetTotalV()-1; i++) {
        ui->AddEdgeTable->setItem(i, 0, new QTableWidgetItem(graph.vertList[i].name.GetStadiumName()));
        ui->AddEdgeTable->setVerticalHeaderItem(i, new QTableWidgetItem(""));
    }
    ui->AddEdgeTable->resizeColumnsToContents();
}

void MainWindow::UpdateAddWeightTable() {
    ui->AddWeightTable->setRowCount(1);
    ui->AddWeightTable->setColumnCount(1);
    ui->AddWeightTable->setHorizontalHeaderItem(0, new QTableWidgetItem(""));
    ui->AddWeightTable->setItem(0, 0, new QTableWidgetItem(""));
    ui->AddWeightTable->setVerticalHeaderItem(0, new QTableWidgetItem(""));
    connect(ui->AddWeightTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedWeight(const QModelIndex&)));
}

void MainWindow::UpdateTripTable(Stadium* temp, int count) {
    ui->TripTable->setRowCount(count-listRemove);
    ui->TripTable->setColumnCount(1);
    ui->TripTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadiums"));

    int j = 0;
    for(int i = listRemove; i < count; i++) {
        ui->TripTable->setItem(j++, 0, new QTableWidgetItem(temp[i].GetStadiumName()));
    }
    ui->TripTable->resizeColumnsToContents();
    listRemove++;

    UpdateTripSouvTable(temp);
}

void MainWindow::UpdateTripSouvTable(Stadium* temp) {
    ui->TripSouvTable->setRowCount(1);
    ui->TripSouvTable->setColumnCount(temp[curID].GetSouvTotal()+2);
    ui->TripSouvTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->TripSouvTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Team"));

    ui->TripSouvTable->setItem(0, 0, new QTableWidgetItem(QString::number(temp[curID].GetID())));
    ui->TripSouvTable->setItem(0, 1, new QTableWidgetItem(temp[curID].GetTeamName()));

    for (int i = 0; i < temp[curID].GetSouvTotal(); i++) {
          ui->TripSouvTable->setHorizontalHeaderItem(i+2, new QTableWidgetItem(temp[curID].GetSouvenirName(i)));
          ui->TripSouvTable->setItem(0, i+2, new QTableWidgetItem(QString::number(temp[curID].GetSouvenirPrice(i))));
    }

    ui->TripSouvTable->setVerticalHeaderItem(0, new QTableWidgetItem(""));

    ui->TripSouvTable->resizeColumnsToContents();
    ui->D_Error->setText("");
    col = -1;
}

void MainWindow::UpdateTripFinTable() {
    ui->TripFinTable->setRowCount(souvBoughtName.size());
    ui->TripFinTable->setColumnCount(4);
    ui->TripFinTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team"));
    ui->TripFinTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->TripFinTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
    ui->TripFinTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity"));
    double totalCost = 0.00;

    for (int i = 0; i < souvBoughtName.size(); i++) {
        ui->TripFinTable->setItem(i, 0, new QTableWidgetItem(souvBoughtTeam.at(i)));
        ui->TripFinTable->setItem(i, 1, new QTableWidgetItem(souvBoughtName.at(i)));
        ui->TripFinTable->setItem(i, 2, new QTableWidgetItem(QString::number(souvBoughtPrice.at(i))));
        ui->TripFinTable->setItem(i, 3, new QTableWidgetItem(QString::number(souvBoughtAmount.at(i))));
        totalCost += souvBoughtPrice.at(i);
    }
    ui->TripFinTable->resizeColumnsToContents();
    ui->DF_TotMil->setText(QString::number(graph.GetTotalMil()));
    ui->TripTotalCost->setText(QString::number(totalCost));
    totalCost = 0;
    graph.SetTotalMil(0);
}

void MainWindow::UpdateTotRevTable() {
    ui->TotRevTable->setRowCount(graph.GetTotalV());
    ui->TotRevTable->setColumnCount(2);
    ui->TotRevTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team"));
    ui->TotRevTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Revenue"));

    for (int i = 0; i < graph.GetTotalV(); i++) {
        ui->TotRevTable->setItem(i, 0, new QTableWidgetItem(graph.vertList[i].name.GetTeamName()));
        ui->TotRevTable->setItem(i, 1, new QTableWidgetItem(QString::number(graph.vertList[i].name.GetTotalRevenue())));
        ui->TotRevTable->setVerticalHeaderItem(i, new QTableWidgetItem(""));
    }
    ui->TotRevTable->resizeColumnsToContents();
}

void MainWindow::UpdateCTripTable() {
    ui->CTripTable->setRowCount(souvBoughtTeam.size());
    ui->CTripTable->setColumnCount(1);
    ui->CTripTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadiums"));

    for (int i = 0; i < souvBoughtTeam.size(); i++) {
        ui->CTripTable->setItem(i, 0, new QTableWidgetItem(souvBoughtTeam.at(i)));
    }
    ui->CTripTable->resizeColumnsToContents();
}

void MainWindow::UpdateCYourTable() {
    ui->CYourTable->setRowCount(souvBoughtName.size());
    ui->CYourTable->setColumnCount(1);
    ui->CYourTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadiums"));

    for (int i = 0; i < souvBoughtName.size(); i++) {
        ui->CYourTable->setItem(i, 0, new QTableWidgetItem(souvBoughtName[i]));
    }
    ui->CYourTable->resizeColumnsToContents();
}

void MainWindow::UpdateEdgesTable() {
    ui->EdgesTable->setRowCount(graph.GetTotalV());
    ui->EdgesTable->setColumnCount(graph.GetTotalV());

    for (int i = 0; i < graph.GetTotalV(); i++) {
        ui->EdgesTable->setHorizontalHeaderItem(i, new QTableWidgetItem(graph.vertList[i].name.GetStadiumName()));
        ui->EdgesTable->setVerticalHeaderItem(i, new QTableWidgetItem(graph.vertList[i].name.GetStadiumName()));
        for (int j = 0; j < graph.GetTotalV(); j++) {
            ui->EdgesTable->setItem(i, j, new QTableWidgetItem(QString::number(graph.GetMatrix()[i][j])));
        }
    }
    ui->EdgesTable->resizeColumnsToContents();
    connect(ui->EdgesTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedEdges(const QModelIndex&)));
}

void MainWindow::UpdateAddSouvTable() {
    ui->AddSouvTable->setRowCount(1);
    ui->AddSouvTable->setColumnCount(2);
    ui->AddSouvTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name of New Souvenir"));
    ui->AddSouvTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price of New Souvenir"));

    ui->AddSouvTable->setItem(0, 0, new QTableWidgetItem(""));
    ui->AddSouvTable->setItem(0, 1, new QTableWidgetItem(""));
    ui->AddSouvTable->setVerticalHeaderItem(0, new QTableWidgetItem(""));

    ui->AddSouvTable->resizeColumnsToContents();

    UpdateAddSouvList();
    connect(ui->AddSouvTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedAddSouv(const QModelIndex&)));
}

void MainWindow::UpdateAddSouvList() {
    ui->AddSouvList->setRowCount(graph.GetTotalV());
    ui->AddSouvList->setColumnCount(1);
    ui->AddSouvList->setHorizontalHeaderItem(0, new QTableWidgetItem("Team"));

    for (int i = 0; i < graph.GetTotalV(); i++) {
        ui->AddSouvList->setItem(i, 0, new QTableWidgetItem(graph.vertList[i].name.GetTeamName()));
        ui->AddSouvList->setVerticalHeaderItem(i, new QTableWidgetItem(""));
    }

    ui->AddSouvList->resizeColumnsToContents();
    ui->AS_Error->setText("");
}

//M O D   S T A D I U M S
void MainWindow::on_ModStadTable_cellClicked(int row1, int column1) {
    row = row1;
    col = column1;
}

void MainWindow::on_ModSouvTable_cellClicked(int row1, int column1) {
    row = row1;
    col = column1;
}

void MainWindow::on_ModSouvList_cellClicked(int row1, int column1) {
    curTeam = row1;
    curCount = 0;
    disconnect(ui->ModSouvTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedSouv(const QModelIndex&)));
    UpdateModSouvTable();
//    ui->AS_Error->setText("");
}

void MainWindow::on_AddStadTable_cellClicked(int row1, int column1) {
    row = row1;
    col = column1;
}

void MainWindow::on_AddEdgeTable_cellClicked(int row1, int column1) {
    row = row1;
    col = column1;
    curTeam = row;
    ui->ADD2_Error->setText("");
}

void MainWindow::on_AddWeightTable_cellClicked(int row1, int column1) { }

void MainWindow::on_TripSouvTable_cellClicked(int row1, int column1) {
    row = row1;
    col = column1;
    ui->D_Error->setText("");
}

void MainWindow::on_CTripTable_cellClicked(int row1, int column1) {
    row = row1;
    col = column1;
}

void MainWindow::on_EdgesTable_cellClicked(int row1, int column1) {
    row = row1;
    col = column1;
}

void MainWindow::on_AddSouvTable_cellClicked(int row1, int column1) {
    col = column1;
}

void MainWindow::on_AddSouvList_cellClicked(int row1, int column1) {
    curTeam = row1;
    curCount = 0;
    ui->AS_Error->setText("");
}

void MainWindow::onDataChangedView(const QModelIndex& value) {
    ui->V_Error->setText("ERROR - Must be admin to change values!");
}

void MainWindow::onDataChangedStad(const QModelIndex& value) {
    if (row != -1) {
//        qDebug() << "This cell has changed:\n\t" << row << " - " << col << "\n\t" << value.data(Qt::DisplayRole).toString() << endl;
        QRegExp re("\\d*");
        ui->MSTA_Error->setText("");
        QSqlQuery query(db);

        switch (col) {
            case 0 : ui->MSTA_Error->setText("ERROR - Cannot edit ID values!");
                break;
            case 1: graph.vertList[row].name.SetTeamName(value.data(Qt::DisplayRole).toString());
                    query.exec("UPDATE stadiums SET teamName='" + value.data(Qt::DisplayRole).toString() + "' WHERE stadiumID=" + QString::number(row));
                break;
            case 2: graph.vertList[row].name.SetStadiumName(value.data(Qt::DisplayRole).toString());
                    query.exec("UPDATE stadiums SET stadiumName='" + value.data(Qt::DisplayRole).toString() + "' WHERE stadiumID=" + QString::number(row));
                break;
            case 3:
                    if (re.exactMatch(value.data(Qt::DisplayRole).toString())) {
                        graph.vertList[row].name.SetCapacity(value.data(Qt::DisplayRole).toDouble());
                        query.exec("UPDATE stadiums SET capacity='" + QString::number(value.data(Qt::DisplayRole).toDouble()) + "' WHERE stadiumID=" + QString::number(row));
                    }
                    else
                        ui->MSTA_Error->setText("ERROR - Value not an numerical value (ex. 1024)!");
                break;
            case 4: graph.vertList[row].name.SetLocation(value.data(Qt::DisplayRole).toString());
                    query.exec("UPDATE stadiums SET location='" + value.data(Qt::DisplayRole).toString() + "' WHERE stadiumID=" + QString::number(row));
                break;
            case 5: graph.vertList[row].name.SetConference(value.data(Qt::DisplayRole).toString());
                    query.exec("UPDATE stadiums SET conference='" + value.data(Qt::DisplayRole).toString() + "' WHERE stadiumID=" + QString::number(row));
                break;
            case 6: graph.vertList[row].name.SetSurfaceType(value.data(Qt::DisplayRole).toString());
                    query.exec("UPDATE stadiums SET surfaceType='" + value.data(Qt::DisplayRole).toString() + "' WHERE stadiumID=" + QString::number(row));
                break;
            case 7: graph.vertList[row].name.SetRoofType(value.data(Qt::DisplayRole).toString());
                    query.exec("UPDATE stadiums SET roofType='" + value.data(Qt::DisplayRole).toString() + "' WHERE stadiumID=" + QString::number(row));
                break;
            case 8: graph.vertList[row].name.SetStarPlayer(value.data(Qt::DisplayRole).toString());
                    query.exec("UPDATE stadiums SET starName='" + value.data(Qt::DisplayRole).toString() + "' WHERE stadiumID=" + QString::number(row));
                break;
            default:
                break;
        };
        row = -1;
    }
}

void MainWindow::onDataChangedSouv(const QModelIndex& value) {
    ui->MSOU_Error->setText("");
    if (row != -1) {
//        qDebug() << "This cell has changed:\n\t" << row << " - " << col << "\n\t" << value.data(Qt::DisplayRole).toString() << endl;
        QRegExp re("[0-9]+(\.[0-9][0-9]?)?");

        if (re.exactMatch(value.data(Qt::DisplayRole).toString())) {
            QSqlQuery query(db);
//            qDebug() << row << " - " << col << " - " << curTeam << " - " << curCount;

            disconnect(ui->ModSouvTable->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChangedSouv(const QModelIndex&)));
            graph.vertList[curTeam].name.SetSouvenirPrice(col+2, value.data(Qt::DisplayRole).toDouble());

            query.exec("UPDATE souvenirs SET '" + graph.vertList[curTeam].name.GetSouvenirName(col) + "'='" + QString::number(value.data(Qt::DisplayRole).toDouble()) + "' WHERE stadiumID=" + QString::number(curTeam));

            UpdateModSouvTable();
        }
        else
            ui->MSOU_Error->setText("ERROR - Value not a valid numerical value (ex. 10.21)!");

        row = -1;
    }
}

void MainWindow::onDataChangedAdd(const QModelIndex& value) {
    ui->ADD_Error->setText("");
    if (row != -1) {
//        qDebug() << "This cell has changed:\n\t" << row << " - " << col << "\n\t" << value.data(Qt::DisplayRole).toString() << endl;
        QRegExp re("\\d*");

        switch (col) {
            case 0: ui->ADD_Error->setText("ERROR - Cannot change ID!");
                break;
            case 1: nTeam = value.data(Qt::DisplayRole).toString();
                break;
            case 2: nStadium = value.data(Qt::DisplayRole).toString();
                break;
            case 3:
                    if (re.exactMatch(value.data(Qt::DisplayRole).toString()))
                        nCapacity = value.data(Qt::DisplayRole).toDouble();
                    else
                        ui->ADD_Error->setText("ERROR - Value not a valid numerical value (ex. 1024)!");
                break;
            case 4: nLocation = value.data(Qt::DisplayRole).toString();
                break;
            case 5: nConference = value.data(Qt::DisplayRole).toString();
                break;
            case 6: nSurface = value.data(Qt::DisplayRole).toString();
                break;
            case 7: nRoof = value.data(Qt::DisplayRole).toString();
                break;
            case 8: nStar = value.data(Qt::DisplayRole).toString();
                break;
            default: //qDebug() << "ERROR - Value not a valid row!";
                break;
        };
        row = -1;
    }
}

void MainWindow::onDataChangedWeight(const QModelIndex& value) {
    QRegExp re("\\d*");
    ui->ADD2_Error->setText("");

    if (col == -2) {
        ui->ADD2_Error->setText("ERROR - Select a stadium!");
        ui->AddWeightTable->clear();
    }
    else if (value.data(Qt::DisplayRole).toInt() == 0) {
        col = -1;
        ui->ADD2_Error->setText("ERROR - Value cannot be a 0!");
        ui->AddWeightTable->clear();
    }
    else if (re.exactMatch(value.data(Qt::DisplayRole).toString())) {
        curWeight = value.data(Qt::DisplayRole).toDouble();
        col = 0;
    }
    else {
        col = -1;
        ui->ADD2_Error->setText("ERROR - Value not an numerical value (ex. 1024)!");
        ui->AddWeightTable->clear();
    }
}

void MainWindow::onDataChangedEdges(const QModelIndex& value) {
    if (row != -1) {
//        qDebug() << "This cell has changed:\n\t" << row << " - " << col << "\n\t" << value.data(Qt::DisplayRole).toString() << endl;
        QRegExp re("\\d*");
        ui->ME_Error->setText("");

        if (re.exactMatch(value.data(Qt::DisplayRole).toString())) {
            QSqlQuery query(db);

            int** temp = graph.GetMatrix();
            temp[row][col] = value.data(Qt::DisplayRole).toInt();
            graph.SetMatrix(temp);

            query.exec("UPDATE edges SET '" + QString::number(row) + "'='" + QString::number(value.data(Qt::DisplayRole).toInt()) + "' WHERE stadiumID=" + QString::number(col));
        }
        else if (value.data(Qt::DisplayRole).toInt() < 0)
            ui->ME_Error->setText("ERROR - Value cannot be a negative number!");
        else
            ui->ME_Error->setText("ERROR - Value not an numerical value (ex. 1024)!");

        row = -1;
    }
}


void MainWindow::onDataChangedAddSouv(const QModelIndex& value) {
//        qDebug() << "This cell has changed:\n\t" << row << " - " << col << "\n\t" << value.data(Qt::DisplayRole).toString() << endl;
        QRegExp re("[0-9]+(\.[0-9][0-9]?)?");
        ui->AS_Error->setText("");

        switch (col) {
            case 0: souvTemp.SetItem(value.data(Qt::DisplayRole).toString());
                break;
            case 1:
                    if (re.exactMatch(value.data(Qt::DisplayRole).toString())) {
                        souvTemp.SetPrice(value.data(Qt::DisplayRole).toDouble());
                        row = 0;
                    }
                    else {
                        ui->AS_Error->setText("ERROR - Value not an numerical value (ex. 10.21)!");
                        row = -1;
                    }
                break;
            default:
                break;
        }
}
