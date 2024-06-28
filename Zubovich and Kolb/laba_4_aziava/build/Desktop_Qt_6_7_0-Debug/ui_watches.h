/********************************************************************************
** Form generated from reading UI file 'watches.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHES_H
#define UI_WATCHES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Watches
{
public:

    void setupUi(QDialog *Watches)
    {
        if (Watches->objectName().isEmpty())
            Watches->setObjectName("Watches");
        Watches->resize(450, 450);

        retranslateUi(Watches);

        QMetaObject::connectSlotsByName(Watches);
    } // setupUi

    void retranslateUi(QDialog *Watches)
    {
        Watches->setWindowTitle(QCoreApplication::translate("Watches", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Watches: public Ui_Watches {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHES_H
