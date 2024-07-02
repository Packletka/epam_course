#include "qmyform.h"
#include "qworkform.h"
#include <QMenu>
#include <QtWidgets>

QMyForm::QMyForm(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* file = new QMenu("&Файл");
    QMenu* info = new QMenu("&Инфо");
    QWorkForm* form = new QWorkForm;

    file->addAction("&Открыть", form, SLOT(slotLoad()));
    info->addAction("&Помощь", this, SLOT(slotInfo()));
    file->addAction("&Сохранить", form, SLOT(slotSave()));
    file->addAction("&Сохранить как", form, SLOT(slotSaveAs()));
    file->addSeparator();
    file->addAction("&Выход", qApp, SLOT(quit()));

    menuBar()->addMenu(file);
    menuBar()->addMenu(info);
    statusBar()->setVisible(false);
    setCentralWidget(form);
    connect(form, SIGNAL(ChangeTitle(const QString&)), SLOT(slotChangeTitle(const QString&)));
}


QMyForm::~QMyForm() {}

void QMyForm::slotInfo()
{
    QMessageBox::about(this, "О программе", "Это простейшее SDI-приложение - блокнот");
}

void QMyForm::slotChangeTitle(const QString& str)
{
    this->setWindowTitle(str);
}


