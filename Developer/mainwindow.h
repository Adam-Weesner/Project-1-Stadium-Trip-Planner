#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "stadium.h"
#include "graph.h"
#include "secdialog.h"
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void InitializeMatrix(int num);
    //Home
    void on_H_AdminB_clicked();
    void on_H_NextB_clicked();
    void on_Exit_clicked();

    //Trip Planner
    void on_T_BackB_clicked();
    void on_T_DefaultB_clicked();
        void on_D_NextB_clicked();
        void on_D_BuyB_clicked();
        void on_D_FinB_clicked();
        void on_DF_BackB_clicked();
    void on_T_CustomB_clicked();
        void on_C_BackB_clicked();
        void on_C_AddB_clicked();
        void on_C_StartB_clicked();
    void on_T_MSTB_clicked();
    void on_T_ViewB_clicked();
    void on_T_BFSB_clicked();
    void on_T_DFSB_clicked();
        //Trips/View/MST
        void on_D_BackB_clicked();
        void on_M_BackB_clicked();
        void on_V_BackB_clicked();
        void on_BFS_BackB_clicked();
        void on_DFS_BackB_clicked();

    //Admin
    void on_A_AddB_clicked();
    void on_A_BackB_clicked();
    void on_A_StadiumsB_clicked();
    void on_A_SouvenirsB_clicked();
    void on_A_AddSouvB_clicked();
    void on_A_EdgesB_clicked();
    //Admin Options
        //Add Stadium
        void on_ADD_BackB_clicked();
        void on_ADD_AddB_clicked();
        void on_ADD2_BackB_clicked();
        void on_ADD2_AddB_clicked();
        //Mod Edges
        void on_ME_BackB_clicked();
        //Add Souvenirs
        void on_AS_BackB_clicked();
        void on_AS_AddB_clicked();
    void on_MSTA_BackB_clicked();
    void on_MSOU_BackB_clicked();
    void on_MSOU_DeleteB_clicked();

    //Updating Tables
    void UpdateViewTable();
    void UpdateModStadTable();
    void UpdateModSouvTable();
    void UpdateModSouvList();
    void UpdateAddStadTable();
    void UpdateAddEdgeTable();
    void UpdateAddWeightTable();
    void UpdateTripTable(Stadium* temp, int count);
    void UpdateTripSouvTable(Stadium* temp);
    void UpdateTripFinTable();
    void UpdateTotRevTable();
    void UpdateCTripTable();
    void UpdateCYourTable();
    void UpdateEdgesTable();
    void UpdateAddSouvTable();
    void UpdateAddSouvList();

    //Modifying
    void on_ModStadTable_cellClicked(int row1, int column1);
    void on_ModSouvTable_cellClicked(int row1, int column1);
    void on_ModSouvList_cellClicked(int row1, int column1);
    void on_AddStadTable_cellClicked(int row1, int column1);
    void on_AddEdgeTable_cellClicked(int row1, int column1);
    void on_AddWeightTable_cellClicked(int row1, int column1);
    void on_TripSouvTable_cellClicked(int row1, int column1);
    void on_CTripTable_cellClicked(int row1, int column1);
    void on_EdgesTable_cellClicked(int row1, int column1);
    void on_AddSouvTable_cellClicked(int row1, int column1);
    void on_AddSouvList_cellClicked(int row1, int column1);

    //When Changed
    void onDataChangedView(const QModelIndex& value);
    void onDataChangedStad(const QModelIndex& value);
    void onDataChangedSouv(const QModelIndex& value);
    void onDataChangedAdd(const QModelIndex& value);
    void onDataChangedWeight(const QModelIndex& value);
    void onDataChangedEdges(const QModelIndex& value);
    void onDataChangedAddSouv(const QModelIndex& value);

private:
    Ui::MainWindow *ui;
    Graph<Stadium,int> graph;
    QSqlDatabase db;
    int totalData;

    long totalCapacity;
    int row;
    int col;
    int curTeam;
    double curWeight;

    Stadium* curTemp;
    int curCount;
    int listRemove;
    int curID;
    Souvenirs souvTemp;

    QList<QString> souvBoughtTeam;
    QList<QString> souvBoughtName;
    QList<double> souvBoughtPrice;
    QList<int> souvBoughtAmount;

    QList<QString> teamName1;
    QList<QString> teamName2;

    //New Stadium
    int nID;
    QString nTeam;
    QString nStadium;
    double nCapacity;
    QString nLocation;
    QString nConference;
    QString nSurface;
    QString nRoof;
    QString nStar;
};

#endif // MAINWINDOW_H
