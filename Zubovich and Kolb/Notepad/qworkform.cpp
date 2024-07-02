#include "qworkform.h"
#include <QFileDialog>
#include <QTextStream>
#include <QPlainTextEdit>

QWorkForm::QWorkForm(QWidget* parent) : QTextEdit(0){}



void QWorkForm::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty())
        return;

    QFile file(str);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();

        filename = str;
        emit ChangeTitle(filename);
    }
}


void QWorkForm::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(nullptr, filename);
    if (!str.isEmpty())
    {
        filename = str;
        slotSave();
    }
}


void QWorkForm::slotSave()
{
    if (filename.isEmpty())
    {
        slotSaveAs();
        return;
    }

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << toPlainText();
        file.close();
        emit ChangeTitle(filename);
    }
}



