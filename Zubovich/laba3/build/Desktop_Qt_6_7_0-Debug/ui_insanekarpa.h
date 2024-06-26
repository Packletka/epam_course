/********************************************************************************
** Form generated from reading UI file 'insanekarpa.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSANEKARPA_H
#define UI_INSANEKARPA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_insaneKarpa
{
public:
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *karpa;

    void setupUi(QDialog *insaneKarpa)
    {
        if (insaneKarpa->objectName().isEmpty())
            insaneKarpa->setObjectName("insaneKarpa");
        insaneKarpa->resize(1219, 731);
        label = new QLabel(insaneKarpa);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 1221, 741));
        progressBar = new QProgressBar(insaneKarpa);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 0, 231, 31));
        progressBar->setValue(24);
        karpa = new QLabel(insaneKarpa);
        karpa->setObjectName("karpa");
        karpa->setGeometry(QRect(20, 580, 71, 71));

        retranslateUi(insaneKarpa);

        QMetaObject::connectSlotsByName(insaneKarpa);
    } // setupUi

    void retranslateUi(QDialog *insaneKarpa)
    {
        insaneKarpa->setWindowTitle(QCoreApplication::translate("insaneKarpa", "Fight with Karpa", nullptr));
        label->setText(QCoreApplication::translate("insaneKarpa", "<html><head/><body><p><img src=\":/files_qrc/wallpaper.jpg\"/></p></body></html>", nullptr));
        karpa->setText(QCoreApplication::translate("insaneKarpa", "<html><head/><body><p><img src=\":/files_qrc/karpa.png\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insaneKarpa: public Ui_insaneKarpa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSANEKARPA_H
