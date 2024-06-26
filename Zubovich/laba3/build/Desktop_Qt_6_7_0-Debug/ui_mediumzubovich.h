/********************************************************************************
** Form generated from reading UI file 'mediumzubovich.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIUMZUBOVICH_H
#define UI_MEDIUMZUBOVICH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_mediumZubovich
{
public:
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *zubovich;

    void setupUi(QDialog *mediumZubovich)
    {
        if (mediumZubovich->objectName().isEmpty())
            mediumZubovich->setObjectName("mediumZubovich");
        mediumZubovich->resize(1219, 731);
        label = new QLabel(mediumZubovich);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -4, 1221, 741));
        progressBar = new QProgressBar(mediumZubovich);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 0, 231, 31));
        progressBar->setValue(24);
        zubovich = new QLabel(mediumZubovich);
        zubovich->setObjectName("zubovich");
        zubovich->setGeometry(QRect(1120, 120, 71, 71));

        retranslateUi(mediumZubovich);

        QMetaObject::connectSlotsByName(mediumZubovich);
    } // setupUi

    void retranslateUi(QDialog *mediumZubovich)
    {
        mediumZubovich->setWindowTitle(QCoreApplication::translate("mediumZubovich", "Fight with Zubovich", nullptr));
        label->setText(QCoreApplication::translate("mediumZubovich", "<html><head/><body><p><img src=\":/files_qrc/wallpaper.jpg\"/></p></body></html>", nullptr));
        zubovich->setText(QCoreApplication::translate("mediumZubovich", "<html><head/><body><p><img src=\":/files_qrc/zubovich.png\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediumZubovich: public Ui_mediumZubovich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIUMZUBOVICH_H
