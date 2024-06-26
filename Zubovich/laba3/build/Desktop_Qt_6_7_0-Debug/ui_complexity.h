/********************************************************************************
** Form generated from reading UI file 'complexity.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPLEXITY_H
#define UI_COMPLEXITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Complexity
{
public:
    QPushButton *mediumMode;
    QPushButton *insaneMode;
    QPushButton *easyMode;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;

    void setupUi(QDialog *Complexity)
    {
        if (Complexity->objectName().isEmpty())
            Complexity->setObjectName("Complexity");
        Complexity->resize(1219, 731);
        mediumMode = new QPushButton(Complexity);
        mediumMode->setObjectName("mediumMode");
        mediumMode->setGeometry(QRect(390, 330, 441, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Gothic")});
        font.setPointSize(16);
        mediumMode->setFont(font);
        mediumMode->setStyleSheet(QString::fromUtf8("color: #FF7518;"));
        insaneMode = new QPushButton(Complexity);
        insaneMode->setObjectName("insaneMode");
        insaneMode->setGeometry(QRect(390, 430, 441, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Uroob")});
        font1.setPointSize(20);
        font1.setItalic(true);
        insaneMode->setFont(font1);
        insaneMode->setStyleSheet(QString::fromUtf8("color: #9400D3;"));
        easyMode = new QPushButton(Complexity);
        easyMode->setObjectName("easyMode");
        easyMode->setGeometry(QRect(390, 230, 441, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Umpush")});
        font2.setPointSize(16);
        easyMode->setFont(font2);
        easyMode->setStyleSheet(QString::fromUtf8("color: #1CAC78;"));
        label = new QLabel(Complexity);
        label->setObjectName("label");
        label->setGeometry(QRect(500, 160, 261, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Uroob")});
        font3.setPointSize(36);
        font3.setBold(true);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: #6495ED;\n"
""));
        label_3 = new QLabel(Complexity);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 220, 71, 71));
        label_4 = new QLabel(Complexity);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(320, 420, 71, 71));
        label_2 = new QLabel(Complexity);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 320, 71, 71));
        label_5 = new QLabel(Complexity);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, -10, 1221, 741));
        label_5->raise();
        mediumMode->raise();
        insaneMode->raise();
        easyMode->raise();
        label->raise();
        label_3->raise();
        label_4->raise();
        label_2->raise();

        retranslateUi(Complexity);

        QMetaObject::connectSlotsByName(Complexity);
    } // setupUi

    void retranslateUi(QDialog *Complexity)
    {
        Complexity->setWindowTitle(QCoreApplication::translate("Complexity", "Choose...", nullptr));
        mediumMode->setText(QCoreApplication::translate("Complexity", "Medium", nullptr));
        insaneMode->setText(QCoreApplication::translate("Complexity", "Insane", nullptr));
        easyMode->setText(QCoreApplication::translate("Complexity", "Easy", nullptr));
        label->setText(QCoreApplication::translate("Complexity", "Choose difficulty", nullptr));
        label_3->setText(QCoreApplication::translate("Complexity", "<html><head/><body><p><img src=\":/files_qrc/aziava.png\"/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Complexity", "<html><head/><body><p><img src=\":/files_qrc/karpa.png\"/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Complexity", "<html><head/><body><p><img src=\":/files_qrc/zubovich.png\"/></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Complexity", "<html><head/><body><p><img src=\":/files_qrc/wallpaper.jpg\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Complexity: public Ui_Complexity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPLEXITY_H
