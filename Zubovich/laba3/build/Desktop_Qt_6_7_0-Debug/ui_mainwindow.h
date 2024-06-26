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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *exitButton;
    QPushButton *startButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1219, 731);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(380, 420, 461, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Z003")});
        font.setPointSize(24);
        font.setItalic(true);
        exitButton->setFont(font);
        exitButton->setStyleSheet(QString::fromUtf8("color: red;"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(380, 240, 461, 101));
        startButton->setFont(font);
        startButton->setStyleSheet(QString::fromUtf8("color: #00FF7F;\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(600, 370, 21, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Z003")});
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: #6495ED;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(510, 180, 201, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Z003")});
        font2.setPointSize(36);
        font2.setBold(true);
        font2.setItalic(true);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: #6495ED;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 1221, 741));
        MainWindow->setCentralWidget(centralwidget);
        label_3->raise();
        exitButton->raise();
        startButton->raise();
        label->raise();
        label_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1219, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start game", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "or", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Main menu", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/files_qrc/wallpaper.jpg\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
