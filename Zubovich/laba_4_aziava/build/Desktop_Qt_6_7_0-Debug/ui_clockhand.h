/********************************************************************************
** Form generated from reading UI file 'clockhand.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKHAND_H
#define UI_CLOCKHAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Clockhand
{
public:

    void setupUi(QDialog *Clockhand)
    {
        if (Clockhand->objectName().isEmpty())
            Clockhand->setObjectName("Clockhand");
        Clockhand->resize(400, 300);

        retranslateUi(Clockhand);

        QMetaObject::connectSlotsByName(Clockhand);
    } // setupUi

    void retranslateUi(QDialog *Clockhand)
    {
        Clockhand->setWindowTitle(QCoreApplication::translate("Clockhand", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clockhand: public Ui_Clockhand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKHAND_H
