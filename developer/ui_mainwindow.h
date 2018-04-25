/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *Home0;
    QLabel *label;
    QPushButton *H_NextB;
    QPushButton *H_AdminB;
    QPushButton *Exit;
    QWidget *TripPlan1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *T_DefaultB;
    QPushButton *T_CustomB;
    QPushButton *T_MSTB;
    QPushButton *T_BFSB;
    QPushButton *T_DFSB;
    QPushButton *T_ViewB;
    QLabel *label_2;
    QPushButton *T_BackB;
    QWidget *Admin2;
    QPushButton *A_BackB;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *A_AddB;
    QPushButton *A_StadiumsB;
    QPushButton *A_SouvenirsB;
    QPushButton *A_AddSouvB;
    QPushButton *A_EdgesB;
    QWidget *Trip3;
    QLabel *label_4;
    QPushButton *D_BackB;
    QTableWidget *TripTable;
    QTableWidget *TripSouvTable;
    QPushButton *D_FinB;
    QPushButton *D_BuyB;
    QPushButton *D_NextB;
    QSpinBox *TripAmount;
    QTextBrowser *D_Error;
    QWidget *CustomTrip4;
    QLabel *label_5;
    QPushButton *C_BackB;
    QTableWidget *CTripTable;
    QPushButton *C_AddB;
    QTableWidget *CYourTable;
    QLabel *label_18;
    QPushButton *C_StartB;
    QWidget *MST5;
    QLabel *label_6;
    QPushButton *M_BackB;
    QTextBrowser *MSTList;
    QTextBrowser *M_Miles;
    QLabel *label_23;
    QWidget *View6;
    QLabel *label_7;
    QPushButton *V_BackB;
    QTableWidget *viewAllTable;
    QLabel *label_11;
    QTextBrowser *totCapacity;
    QTextBrowser *V_Error;
    QWidget *Add7;
    QLabel *label_8;
    QPushButton *ADD_BackB;
    QTableWidget *AddStadTable;
    QPushButton *ADD_AddB;
    QTextBrowser *ADD_Error;
    QWidget *ModStadiums8;
    QLabel *label_9;
    QPushButton *MSTA_BackB;
    QTableWidget *ModStadTable;
    QTextBrowser *MSTA_Error;
    QWidget *ModSouvenirs9;
    QLabel *label_10;
    QPushButton *MSOU_BackB;
    QTableWidget *ModSouvTable;
    QTextBrowser *MSOU_Error;
    QTableWidget *ModSouvList;
    QPushButton *MSOU_DeleteB;
    QWidget *BFS10;
    QPushButton *BFS_BackB;
    QLabel *label_12;
    QTextBrowser *BFSList;
    QTextBrowser *BFS_Miles;
    QLabel *label_24;
    QWidget *DFS11;
    QPushButton *DFS_BackB;
    QLabel *label_13;
    QTextBrowser *DFSList;
    QTextBrowser *DFS_Miles;
    QLabel *label_25;
    QWidget *AddTwo12;
    QLabel *label_14;
    QPushButton *ADD2_BackB;
    QTableWidget *AddEdgeTable;
    QPushButton *ADD2_AddB;
    QLabel *label_15;
    QTableWidget *AddWeightTable;
    QTextBrowser *ADD2_Error;
    QWidget *TripFin13;
    QLabel *label_16;
    QTableWidget *TripFinTable;
    QPushButton *DF_BackB;
    QTextBrowser *DF_TotMil;
    QLabel *label_17;
    QTextBrowser *TripTotalCost;
    QLabel *label_19;
    QTableWidget *TotRevTable;
    QTextBrowser *GrandTotal;
    QLabel *label_26;
    QWidget *ModEdges14;
    QLabel *label_20;
    QPushButton *ME_BackB;
    QTableWidget *EdgesTable;
    QTextBrowser *ME_Error;
    QWidget *AddSouv15;
    QLabel *label_22;
    QPushButton *AS_BackB;
    QTableWidget *AddSouvTable;
    QTableWidget *AddSouvList;
    QTextBrowser *AS_Error;
    QPushButton *AS_AddB;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 450);
        MainWindow->setStyleSheet(QLatin1String("QToolTip\n"
"{\n"
"     border: 1px solid black;\n"
"     background-color: #ffa02f;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619);\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0.2 #3"
                        "43434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d);\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #b1b1b1;\n"
""
                        "    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0,"
                        " y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848"
                        ");\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border"
                        ": 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
""
                        "QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
""
                        "QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white"
                        ";\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
""
                        "}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    background-color: #d7801a;\n"
"    width: 2.15px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradi"
                        "ent(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #ffaa00,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox"
                        "::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 900, 400));
        Home0 = new QWidget();
        Home0->setObjectName(QStringLiteral("Home0"));
        label = new QLabel(Home0);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 10, 231, 61));
        H_NextB = new QPushButton(Home0);
        H_NextB->setObjectName(QStringLiteral("H_NextB"));
        H_NextB->setGeometry(QRect(600, 200, 75, 23));
        H_AdminB = new QPushButton(Home0);
        H_AdminB->setObjectName(QStringLiteral("H_AdminB"));
        H_AdminB->setGeometry(QRect(170, 200, 91, 23));
        Exit = new QPushButton(Home0);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setGeometry(QRect(390, 340, 75, 23));
        stackedWidget->addWidget(Home0);
        TripPlan1 = new QWidget();
        TripPlan1->setObjectName(QStringLiteral("TripPlan1"));
        verticalLayoutWidget = new QWidget(TripPlan1);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(390, 40, 111, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        T_DefaultB = new QPushButton(verticalLayoutWidget);
        T_DefaultB->setObjectName(QStringLiteral("T_DefaultB"));

        verticalLayout->addWidget(T_DefaultB);

        T_CustomB = new QPushButton(verticalLayoutWidget);
        T_CustomB->setObjectName(QStringLiteral("T_CustomB"));

        verticalLayout->addWidget(T_CustomB);

        T_MSTB = new QPushButton(verticalLayoutWidget);
        T_MSTB->setObjectName(QStringLiteral("T_MSTB"));

        verticalLayout->addWidget(T_MSTB);

        T_BFSB = new QPushButton(verticalLayoutWidget);
        T_BFSB->setObjectName(QStringLiteral("T_BFSB"));

        verticalLayout->addWidget(T_BFSB);

        T_DFSB = new QPushButton(verticalLayoutWidget);
        T_DFSB->setObjectName(QStringLiteral("T_DFSB"));

        verticalLayout->addWidget(T_DFSB);

        T_ViewB = new QPushButton(verticalLayoutWidget);
        T_ViewB->setObjectName(QStringLiteral("T_ViewB"));

        verticalLayout->addWidget(T_ViewB);

        label_2 = new QLabel(TripPlan1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 10, 61, 16));
        T_BackB = new QPushButton(TripPlan1);
        T_BackB->setObjectName(QStringLiteral("T_BackB"));
        T_BackB->setGeometry(QRect(20, 350, 75, 23));
        stackedWidget->addWidget(TripPlan1);
        Admin2 = new QWidget();
        Admin2->setObjectName(QStringLiteral("Admin2"));
        A_BackB = new QPushButton(Admin2);
        A_BackB->setObjectName(QStringLiteral("A_BackB"));
        A_BackB->setGeometry(QRect(20, 350, 75, 23));
        label_3 = new QLabel(Admin2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 10, 61, 16));
        verticalLayoutWidget_2 = new QWidget(Admin2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(360, 80, 160, 221));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        A_AddB = new QPushButton(verticalLayoutWidget_2);
        A_AddB->setObjectName(QStringLiteral("A_AddB"));

        verticalLayout_2->addWidget(A_AddB);

        A_StadiumsB = new QPushButton(verticalLayoutWidget_2);
        A_StadiumsB->setObjectName(QStringLiteral("A_StadiumsB"));

        verticalLayout_2->addWidget(A_StadiumsB);

        A_SouvenirsB = new QPushButton(verticalLayoutWidget_2);
        A_SouvenirsB->setObjectName(QStringLiteral("A_SouvenirsB"));

        verticalLayout_2->addWidget(A_SouvenirsB);

        A_AddSouvB = new QPushButton(verticalLayoutWidget_2);
        A_AddSouvB->setObjectName(QStringLiteral("A_AddSouvB"));

        verticalLayout_2->addWidget(A_AddSouvB);

        A_EdgesB = new QPushButton(verticalLayoutWidget_2);
        A_EdgesB->setObjectName(QStringLiteral("A_EdgesB"));

        verticalLayout_2->addWidget(A_EdgesB);

        stackedWidget->addWidget(Admin2);
        Trip3 = new QWidget();
        Trip3->setObjectName(QStringLiteral("Trip3"));
        label_4 = new QLabel(Trip3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 10, 61, 16));
        D_BackB = new QPushButton(Trip3);
        D_BackB->setObjectName(QStringLiteral("D_BackB"));
        D_BackB->setGeometry(QRect(20, 350, 75, 23));
        TripTable = new QTableWidget(Trip3);
        TripTable->setObjectName(QStringLiteral("TripTable"));
        TripTable->setGeometry(QRect(610, 0, 256, 381));
        TripSouvTable = new QTableWidget(Trip3);
        TripSouvTable->setObjectName(QStringLiteral("TripSouvTable"));
        TripSouvTable->setGeometry(QRect(40, 40, 561, 51));
        D_FinB = new QPushButton(Trip3);
        D_FinB->setObjectName(QStringLiteral("D_FinB"));
        D_FinB->setGeometry(QRect(270, 350, 89, 22));
        D_BuyB = new QPushButton(Trip3);
        D_BuyB->setObjectName(QStringLiteral("D_BuyB"));
        D_BuyB->setGeometry(QRect(270, 110, 89, 22));
        D_NextB = new QPushButton(Trip3);
        D_NextB->setObjectName(QStringLiteral("D_NextB"));
        D_NextB->setGeometry(QRect(270, 220, 89, 22));
        TripAmount = new QSpinBox(Trip3);
        TripAmount->setObjectName(QStringLiteral("TripAmount"));
        TripAmount->setGeometry(QRect(370, 110, 42, 22));
        D_Error = new QTextBrowser(Trip3);
        D_Error->setObjectName(QStringLiteral("D_Error"));
        D_Error->setGeometry(QRect(20, 110, 231, 21));
        D_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        D_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(Trip3);
        CustomTrip4 = new QWidget();
        CustomTrip4->setObjectName(QStringLiteral("CustomTrip4"));
        label_5 = new QLabel(CustomTrip4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(410, 10, 61, 16));
        C_BackB = new QPushButton(CustomTrip4);
        C_BackB->setObjectName(QStringLiteral("C_BackB"));
        C_BackB->setGeometry(QRect(20, 350, 75, 23));
        CTripTable = new QTableWidget(CustomTrip4);
        CTripTable->setObjectName(QStringLiteral("CTripTable"));
        CTripTable->setGeometry(QRect(620, 10, 211, 381));
        C_AddB = new QPushButton(CustomTrip4);
        C_AddB->setObjectName(QStringLiteral("C_AddB"));
        C_AddB->setGeometry(QRect(450, 170, 81, 23));
        CYourTable = new QTableWidget(CustomTrip4);
        CYourTable->setObjectName(QStringLiteral("CYourTable"));
        CYourTable->setGeometry(QRect(120, 30, 251, 361));
        label_18 = new QLabel(CustomTrip4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(200, 10, 101, 16));
        C_StartB = new QPushButton(CustomTrip4);
        C_StartB->setObjectName(QStringLiteral("C_StartB"));
        C_StartB->setGeometry(QRect(450, 340, 75, 23));
        stackedWidget->addWidget(CustomTrip4);
        MST5 = new QWidget();
        MST5->setObjectName(QStringLiteral("MST5"));
        label_6 = new QLabel(MST5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(450, 0, 21, 16));
        M_BackB = new QPushButton(MST5);
        M_BackB->setObjectName(QStringLiteral("M_BackB"));
        M_BackB->setGeometry(QRect(10, 360, 75, 23));
        MSTList = new QTextBrowser(MST5);
        MSTList->setObjectName(QStringLiteral("MSTList"));
        MSTList->setGeometry(QRect(180, 20, 501, 361));
        M_Miles = new QTextBrowser(MST5);
        M_Miles->setObjectName(QStringLiteral("M_Miles"));
        M_Miles->setGeometry(QRect(760, 360, 101, 21));
        M_Miles->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        M_Miles->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_23 = new QLabel(MST5);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(700, 360, 51, 20));
        stackedWidget->addWidget(MST5);
        View6 = new QWidget();
        View6->setObjectName(QStringLiteral("View6"));
        label_7 = new QLabel(View6);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(400, 0, 81, 20));
        V_BackB = new QPushButton(View6);
        V_BackB->setObjectName(QStringLiteral("V_BackB"));
        V_BackB->setGeometry(QRect(10, 360, 75, 23));
        viewAllTable = new QTableWidget(View6);
        viewAllTable->setObjectName(QStringLiteral("viewAllTable"));
        viewAllTable->setGeometry(QRect(10, 40, 881, 311));
        viewAllTable->setSortingEnabled(true);
        label_11 = new QLabel(View6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(230, 360, 111, 20));
        totCapacity = new QTextBrowser(View6);
        totCapacity->setObjectName(QStringLiteral("totCapacity"));
        totCapacity->setGeometry(QRect(350, 360, 141, 20));
        totCapacity->setFocusPolicy(Qt::WheelFocus);
        totCapacity->setAcceptDrops(true);
        totCapacity->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        totCapacity->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        V_Error = new QTextBrowser(View6);
        V_Error->setObjectName(QStringLiteral("V_Error"));
        V_Error->setGeometry(QRect(525, 360, 301, 21));
        V_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        V_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(View6);
        Add7 = new QWidget();
        Add7->setObjectName(QStringLiteral("Add7"));
        label_8 = new QLabel(Add7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(410, 0, 61, 16));
        ADD_BackB = new QPushButton(Add7);
        ADD_BackB->setObjectName(QStringLiteral("ADD_BackB"));
        ADD_BackB->setGeometry(QRect(10, 350, 75, 23));
        AddStadTable = new QTableWidget(Add7);
        AddStadTable->setObjectName(QStringLiteral("AddStadTable"));
        AddStadTable->setGeometry(QRect(150, 40, 591, 41));
        ADD_AddB = new QPushButton(Add7);
        ADD_AddB->setObjectName(QStringLiteral("ADD_AddB"));
        ADD_AddB->setGeometry(QRect(390, 110, 75, 23));
        ADD_Error = new QTextBrowser(Add7);
        ADD_Error->setObjectName(QStringLiteral("ADD_Error"));
        ADD_Error->setGeometry(QRect(510, 230, 311, 21));
        ADD_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ADD_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(Add7);
        ModStadiums8 = new QWidget();
        ModStadiums8->setObjectName(QStringLiteral("ModStadiums8"));
        label_9 = new QLabel(ModStadiums8);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(410, 0, 81, 16));
        MSTA_BackB = new QPushButton(ModStadiums8);
        MSTA_BackB->setObjectName(QStringLiteral("MSTA_BackB"));
        MSTA_BackB->setGeometry(QRect(20, 360, 75, 23));
        ModStadTable = new QTableWidget(ModStadiums8);
        ModStadTable->setObjectName(QStringLiteral("ModStadTable"));
        ModStadTable->setGeometry(QRect(10, 30, 881, 321));
        MSTA_Error = new QTextBrowser(ModStadiums8);
        MSTA_Error->setObjectName(QStringLiteral("MSTA_Error"));
        MSTA_Error->setGeometry(QRect(510, 370, 351, 21));
        MSTA_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MSTA_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(ModStadiums8);
        ModSouvenirs9 = new QWidget();
        ModSouvenirs9->setObjectName(QStringLiteral("ModSouvenirs9"));
        label_10 = new QLabel(ModSouvenirs9);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(410, 0, 91, 16));
        MSOU_BackB = new QPushButton(ModSouvenirs9);
        MSOU_BackB->setObjectName(QStringLiteral("MSOU_BackB"));
        MSOU_BackB->setGeometry(QRect(20, 360, 75, 23));
        ModSouvTable = new QTableWidget(ModSouvenirs9);
        ModSouvTable->setObjectName(QStringLiteral("ModSouvTable"));
        ModSouvTable->setGeometry(QRect(240, 140, 651, 61));
        MSOU_Error = new QTextBrowser(ModSouvenirs9);
        MSOU_Error->setObjectName(QStringLiteral("MSOU_Error"));
        MSOU_Error->setGeometry(QRect(500, 370, 331, 21));
        MSOU_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MSOU_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ModSouvList = new QTableWidget(ModSouvenirs9);
        ModSouvList->setObjectName(QStringLiteral("ModSouvList"));
        ModSouvList->setGeometry(QRect(10, 0, 211, 331));
        MSOU_DeleteB = new QPushButton(ModSouvenirs9);
        MSOU_DeleteB->setObjectName(QStringLiteral("MSOU_DeleteB"));
        MSOU_DeleteB->setGeometry(QRect(630, 280, 101, 23));
        stackedWidget->addWidget(ModSouvenirs9);
        BFS10 = new QWidget();
        BFS10->setObjectName(QStringLiteral("BFS10"));
        BFS_BackB = new QPushButton(BFS10);
        BFS_BackB->setObjectName(QStringLiteral("BFS_BackB"));
        BFS_BackB->setGeometry(QRect(10, 360, 75, 23));
        label_12 = new QLabel(BFS10);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(390, 0, 46, 13));
        BFSList = new QTextBrowser(BFS10);
        BFSList->setObjectName(QStringLiteral("BFSList"));
        BFSList->setGeometry(QRect(130, 20, 521, 361));
        BFS_Miles = new QTextBrowser(BFS10);
        BFS_Miles->setObjectName(QStringLiteral("BFS_Miles"));
        BFS_Miles->setGeometry(QRect(730, 360, 101, 21));
        BFS_Miles->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        BFS_Miles->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_24 = new QLabel(BFS10);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(670, 360, 51, 20));
        stackedWidget->addWidget(BFS10);
        DFS11 = new QWidget();
        DFS11->setObjectName(QStringLiteral("DFS11"));
        DFS_BackB = new QPushButton(DFS11);
        DFS_BackB->setObjectName(QStringLiteral("DFS_BackB"));
        DFS_BackB->setGeometry(QRect(20, 360, 75, 23));
        label_13 = new QLabel(DFS11);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(380, 0, 46, 13));
        DFSList = new QTextBrowser(DFS11);
        DFSList->setObjectName(QStringLiteral("DFSList"));
        DFSList->setGeometry(QRect(150, 20, 491, 361));
        DFS_Miles = new QTextBrowser(DFS11);
        DFS_Miles->setObjectName(QStringLiteral("DFS_Miles"));
        DFS_Miles->setGeometry(QRect(720, 360, 111, 21));
        DFS_Miles->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        DFS_Miles->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_25 = new QLabel(DFS11);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(660, 360, 51, 16));
        stackedWidget->addWidget(DFS11);
        AddTwo12 = new QWidget();
        AddTwo12->setObjectName(QStringLiteral("AddTwo12"));
        label_14 = new QLabel(AddTwo12);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(350, 0, 61, 16));
        ADD2_BackB = new QPushButton(AddTwo12);
        ADD2_BackB->setObjectName(QStringLiteral("ADD2_BackB"));
        ADD2_BackB->setGeometry(QRect(400, 350, 75, 23));
        AddEdgeTable = new QTableWidget(AddTwo12);
        AddEdgeTable->setObjectName(QStringLiteral("AddEdgeTable"));
        AddEdgeTable->setGeometry(QRect(540, 10, 256, 351));
        ADD2_AddB = new QPushButton(AddTwo12);
        ADD2_AddB->setObjectName(QStringLiteral("ADD2_AddB"));
        ADD2_AddB->setGeometry(QRect(420, 220, 75, 23));
        label_15 = new QLabel(AddTwo12);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(440, 140, 41, 20));
        AddWeightTable = new QTableWidget(AddTwo12);
        AddWeightTable->setObjectName(QStringLiteral("AddWeightTable"));
        AddWeightTable->setGeometry(QRect(410, 160, 101, 21));
        AddWeightTable->setFrameShape(QFrame::NoFrame);
        AddWeightTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AddWeightTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AddWeightTable->setShowGrid(true);
        AddWeightTable->horizontalHeader()->setVisible(false);
        AddWeightTable->verticalHeader()->setVisible(false);
        AddWeightTable->verticalHeader()->setHighlightSections(false);
        ADD2_Error = new QTextBrowser(AddTwo12);
        ADD2_Error->setObjectName(QStringLiteral("ADD2_Error"));
        ADD2_Error->setGeometry(QRect(75, 160, 291, 21));
        ADD2_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ADD2_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(AddTwo12);
        TripFin13 = new QWidget();
        TripFin13->setObjectName(QStringLiteral("TripFin13"));
        label_16 = new QLabel(TripFin13);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(390, 10, 61, 16));
        TripFinTable = new QTableWidget(TripFin13);
        TripFinTable->setObjectName(QStringLiteral("TripFinTable"));
        TripFinTable->setGeometry(QRect(180, 30, 351, 291));
        DF_BackB = new QPushButton(TripFin13);
        DF_BackB->setObjectName(QStringLiteral("DF_BackB"));
        DF_BackB->setGeometry(QRect(20, 360, 75, 23));
        DF_TotMil = new QTextBrowser(TripFin13);
        DF_TotMil->setObjectName(QStringLiteral("DF_TotMil"));
        DF_TotMil->setGeometry(QRect(420, 360, 111, 21));
        DF_TotMil->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        DF_TotMil->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_17 = new QLabel(TripFin13);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(360, 360, 51, 16));
        TripTotalCost = new QTextBrowser(TripFin13);
        TripTotalCost->setObjectName(QStringLiteral("TripTotalCost"));
        TripTotalCost->setGeometry(QRect(420, 330, 111, 20));
        TripTotalCost->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TripTotalCost->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_19 = new QLabel(TripFin13);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(360, 330, 51, 20));
        TotRevTable = new QTableWidget(TripFin13);
        TotRevTable->setObjectName(QStringLiteral("TotRevTable"));
        TotRevTable->setGeometry(QRect(600, 30, 251, 291));
        GrandTotal = new QTextBrowser(TripFin13);
        GrandTotal->setObjectName(QStringLiteral("GrandTotal"));
        GrandTotal->setGeometry(QRect(750, 330, 101, 21));
        GrandTotal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        GrandTotal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_26 = new QLabel(TripFin13);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(630, 330, 111, 20));
        stackedWidget->addWidget(TripFin13);
        ModEdges14 = new QWidget();
        ModEdges14->setObjectName(QStringLiteral("ModEdges14"));
        label_20 = new QLabel(ModEdges14);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(410, 0, 71, 16));
        ME_BackB = new QPushButton(ModEdges14);
        ME_BackB->setObjectName(QStringLiteral("ME_BackB"));
        ME_BackB->setGeometry(QRect(20, 360, 75, 23));
        EdgesTable = new QTableWidget(ModEdges14);
        EdgesTable->setObjectName(QStringLiteral("EdgesTable"));
        EdgesTable->setGeometry(QRect(10, 30, 881, 321));
        ME_Error = new QTextBrowser(ModEdges14);
        ME_Error->setObjectName(QStringLiteral("ME_Error"));
        ME_Error->setGeometry(QRect(565, 360, 321, 21));
        ME_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ME_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(ModEdges14);
        AddSouv15 = new QWidget();
        AddSouv15->setObjectName(QStringLiteral("AddSouv15"));
        label_22 = new QLabel(AddSouv15);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(390, 0, 71, 16));
        AS_BackB = new QPushButton(AddSouv15);
        AS_BackB->setObjectName(QStringLiteral("AS_BackB"));
        AS_BackB->setGeometry(QRect(20, 360, 75, 23));
        AddSouvTable = new QTableWidget(AddSouv15);
        AddSouvTable->setObjectName(QStringLiteral("AddSouvTable"));
        AddSouvTable->setGeometry(QRect(280, 30, 301, 41));
        AddSouvList = new QTableWidget(AddSouv15);
        AddSouvList->setObjectName(QStringLiteral("AddSouvList"));
        AddSouvList->setGeometry(QRect(690, 10, 171, 381));
        AS_Error = new QTextBrowser(AddSouv15);
        AS_Error->setObjectName(QStringLiteral("AS_Error"));
        AS_Error->setGeometry(QRect(20, 180, 256, 21));
        AS_Error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AS_Error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AS_AddB = new QPushButton(AddSouv15);
        AS_AddB->setObjectName(QStringLiteral("AS_AddB"));
        AS_AddB->setGeometry(QRect(390, 100, 75, 23));
        stackedWidget->addWidget(AddSouv15);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(12);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">Football Fantasy</span></p></body></html>", 0));
        H_NextB->setText(QApplication::translate("MainWindow", "Trip Planner", 0));
        H_AdminB->setText(QApplication::translate("MainWindow", "Administration", 0));
        Exit->setText(QApplication::translate("MainWindow", "Exit", 0));
        T_DefaultB->setText(QApplication::translate("MainWindow", "Default Trip", 0));
        T_CustomB->setText(QApplication::translate("MainWindow", "Custom Trip", 0));
        T_MSTB->setText(QApplication::translate("MainWindow", "View MST", 0));
        T_BFSB->setText(QApplication::translate("MainWindow", "BFS", 0));
        T_DFSB->setText(QApplication::translate("MainWindow", "DFS", 0));
        T_ViewB->setText(QApplication::translate("MainWindow", "View All Stadiums", 0));
        label_2->setText(QApplication::translate("MainWindow", "Trip Planner", 0));
        T_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        A_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_3->setText(QApplication::translate("MainWindow", "Admin Page", 0));
        A_AddB->setText(QApplication::translate("MainWindow", "Add Stadium ", 0));
        A_StadiumsB->setText(QApplication::translate("MainWindow", "Modify Stadiums", 0));
        A_SouvenirsB->setText(QApplication::translate("MainWindow", "Modify Souvenirs", 0));
        A_AddSouvB->setText(QApplication::translate("MainWindow", "Add Souvenirs", 0));
        A_EdgesB->setText(QApplication::translate("MainWindow", "Modify Edges", 0));
        label_4->setText(QApplication::translate("MainWindow", "Default Trip", 0));
        D_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        D_FinB->setText(QApplication::translate("MainWindow", "Finish", 0));
        D_BuyB->setText(QApplication::translate("MainWindow", "Buy Souvenir", 0));
        D_NextB->setText(QApplication::translate("MainWindow", "Next Stadium", 0));
        label_5->setText(QApplication::translate("MainWindow", "Custom Trip", 0));
        C_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        C_AddB->setText(QApplication::translate("MainWindow", "Add Stadium", 0));
        label_18->setText(QApplication::translate("MainWindow", "Your List of Stadiums", 0));
        C_StartB->setText(QApplication::translate("MainWindow", "Start Trip", 0));
        label_6->setText(QApplication::translate("MainWindow", "MST", 0));
        M_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_23->setText(QApplication::translate("MainWindow", "Total Miles:", 0));
        label_7->setText(QApplication::translate("MainWindow", "View All Stadiums", 0));
        V_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_11->setText(QApplication::translate("MainWindow", "Total Seating Capacity:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Add Stadium", 0));
        ADD_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        ADD_AddB->setText(QApplication::translate("MainWindow", "Add", 0));
        label_9->setText(QApplication::translate("MainWindow", "Modify Stadiums", 0));
        MSTA_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_10->setText(QApplication::translate("MainWindow", "Modify Souvenirs", 0));
        MSOU_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        MSOU_DeleteB->setText(QApplication::translate("MainWindow", "Delete Souvenir", 0));
        BFS_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_12->setText(QApplication::translate("MainWindow", "BFS", 0));
        label_24->setText(QApplication::translate("MainWindow", "Total Miles:", 0));
        DFS_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_13->setText(QApplication::translate("MainWindow", "DFS", 0));
        label_25->setText(QApplication::translate("MainWindow", "Total Miles:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Select Edges", 0));
        ADD2_BackB->setText(QApplication::translate("MainWindow", "Finish", 0));
        ADD2_AddB->setText(QApplication::translate("MainWindow", "Add Edge", 0));
        label_15->setText(QApplication::translate("MainWindow", "Weight", 0));
        label_16->setText(QApplication::translate("MainWindow", "Trip Finished!", 0));
        DF_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_17->setText(QApplication::translate("MainWindow", "Total Miles:", 0));
        label_19->setText(QApplication::translate("MainWindow", "Total Cost:", 0));
        label_26->setText(QApplication::translate("MainWindow", "Grand Total Revenue:", 0));
        label_20->setText(QApplication::translate("MainWindow", "Modify Edges", 0));
        ME_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        label_22->setText(QApplication::translate("MainWindow", "Add Souvenirs", 0));
        AS_BackB->setText(QApplication::translate("MainWindow", "Back", 0));
        AS_AddB->setText(QApplication::translate("MainWindow", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
