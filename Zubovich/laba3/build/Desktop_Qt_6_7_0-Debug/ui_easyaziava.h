/********************************************************************************
** Form generated from reading UI file 'easyaziava.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYAZIAVA_H
#define UI_EASYAZIAVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_easyAziava
{
public:
    QLabel *aziava;
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QDialog *easyAziava)
    {
        if (easyAziava->objectName().isEmpty())
            easyAziava->setObjectName("easyAziava");
        easyAziava->resize(1219, 731);
        aziava = new QLabel(easyAziava);
        aziava->setObjectName("aziava");
        aziava->setGeometry(QRect(490, 340, 71, 71));
        progressBar = new QProgressBar(easyAziava);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 0, 231, 31));
        progressBar->setValue(24);
        label = new QLabel(easyAziava);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1221, 731));
        label->raise();
        progressBar->raise();
        aziava->raise();

        retranslateUi(easyAziava);

        QMetaObject::connectSlotsByName(easyAziava);
    } // setupUi

    void retranslateUi(QDialog *easyAziava)
    {
        easyAziava->setWindowTitle(QCoreApplication::translate("easyAziava", "Fight with Aziava", nullptr));
        aziava->setText(QCoreApplication::translate("easyAziava", "<html><head/><body><p><img src=\":/files_qrc/aziava.png\"/></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("easyAziava", "<html><head/><body><p><img src=\":/files_qrc/wallpaper.jpg\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class easyAziava: public Ui_easyAziava {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYAZIAVA_H
