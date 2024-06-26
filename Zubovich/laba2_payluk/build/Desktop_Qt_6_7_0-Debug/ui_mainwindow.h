/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionHow_does_it_work;
    QWidget *centralwidget;
    QPushButton *CalculateButton;
    QLabel *labelNumDays;
    QLabel *labelPhysical;
    QLabel *labelEmotional;
    QLabel *labelIntellectual;
    QLabel *labelGraphic;
    QLabel *labelRed;
    QLabel *labelTodaysDate;
    QLabel *labelBirthDate;
    QDateEdit *dateEdit1;
    QDateEdit *dateEdit2;
    QLabel *labelBlack;
    QLabel *labelBlue;
    QLabel *label;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../LLL/img/Open.svg.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../LLL/img/Save.svg.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionHow_does_it_work = new QAction(MainWindow);
        actionHow_does_it_work->setObjectName("actionHow_does_it_work");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../LLL/img/Info.svg.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionHow_does_it_work->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        CalculateButton = new QPushButton(centralwidget);
        CalculateButton->setObjectName("CalculateButton");
        CalculateButton->setGeometry(QRect(350, 110, 83, 29));
        labelNumDays = new QLabel(centralwidget);
        labelNumDays->setObjectName("labelNumDays");
        labelNumDays->setGeometry(QRect(470, 120, 270, 20));
        labelPhysical = new QLabel(centralwidget);
        labelPhysical->setObjectName("labelPhysical");
        labelPhysical->setGeometry(QRect(600, 10, 191, 20));
        labelEmotional = new QLabel(centralwidget);
        labelEmotional->setObjectName("labelEmotional");
        labelEmotional->setGeometry(QRect(600, 40, 191, 21));
        labelIntellectual = new QLabel(centralwidget);
        labelIntellectual->setObjectName("labelIntellectual");
        labelIntellectual->setGeometry(QRect(600, 70, 191, 20));
        labelGraphic = new QLabel(centralwidget);
        labelGraphic->setObjectName("labelGraphic");
        labelGraphic->setGeometry(QRect(10, 250, 781, 291));
        labelRed = new QLabel(centralwidget);
        labelRed->setObjectName("labelRed");
        labelRed->setGeometry(QRect(530, 10, 61, 20));
        labelTodaysDate = new QLabel(centralwidget);
        labelTodaysDate->setObjectName("labelTodaysDate");
        labelTodaysDate->setGeometry(QRect(290, 50, 80, 20));
        labelBirthDate = new QLabel(centralwidget);
        labelBirthDate->setObjectName("labelBirthDate");
        labelBirthDate->setGeometry(QRect(290, 20, 90, 30));
        dateEdit1 = new QDateEdit(centralwidget);
        dateEdit1->setObjectName("dateEdit1");
        dateEdit1->setGeometry(QRect(400, 20, 100, 29));
        dateEdit2 = new QDateEdit(centralwidget);
        dateEdit2->setObjectName("dateEdit2");
        dateEdit2->setGeometry(QRect(400, 50, 100, 29));
        labelBlack = new QLabel(centralwidget);
        labelBlack->setObjectName("labelBlack");
        labelBlack->setGeometry(QRect(530, 70, 50, 20));
        labelBlue = new QLabel(centralwidget);
        labelBlue->setObjectName("labelBlue");
        labelBlue->setGeometry(QRect(530, 40, 40, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, -10, 220, 230));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuHelp->addAction(actionHow_does_it_work);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHow_does_it_work->setText(QCoreApplication::translate("MainWindow", "How does it work", nullptr));
        CalculateButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\321\203\320\271!!!", nullptr));
        labelNumDays->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\247\320\270\321\201\320\273\320\276 \320\264\320\275\320\265\320\271 \321\201\320\276 \320\264\320\275\321\217 \320\240\320\276\320\266\320\264\320\265\320\275\320\270\321\217:</p></body></html>", nullptr));
        labelPhysical->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\271:</p></body></html>", nullptr));
        labelEmotional->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\255\320\274\320\276\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\271:</p></body></html>", nullptr));
        labelIntellectual->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202\321\203\320\260\320\273\321\214\320\275\321\213\320\271:</p></body></html>", nullptr));
        labelGraphic->setText(QString());
        labelRed->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#aa0000;\">\320\272\321\200\320\260\321\201\320\275\321\213\320\271</span></p></body></html>", nullptr));
        labelTodaysDate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203:</p></body></html>", nullptr));
        labelBirthDate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:</p></body></html>", nullptr));
        labelBlack->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#1e1e1e;\">\321\207\320\265\321\200\320\275\321\213\320\271</span></p></body></html>", nullptr));
        labelBlue->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#0000ff;\">\321\201\320\270\320\275\320\270\320\271</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/img/photo_2024-04-01_12-52-13.jpg\"/></p></body></html>", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
