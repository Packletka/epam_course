#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
QTextStream& operator << (QTextStream& out, QList<QStandardItem *> standardItemsList) {
    for (QStandardItem* item : standardItemsList) {
        out << item->text() << ",";
    }
    out << "\n";
    return out;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(3);
    csvModel->setHorizontalHeaderLabels(QStringList() << "1" << "2" << "3");
    ui->tableView->setModel(csvModel);
    ui -> tableView -> setEditTriggers(QAbstractItemView::DoubleClicked);
    QString filepath = QDir::currentPath();
    QFile file(filepath + "/work.csv");
    QFile file_2("work_2.csv");
    if ( !file.open(QIODevice::ReadOnly | QFile::Text) || !file_2.open(QIODevice::WriteOnly | QFile::Text)) {
        qDebug() << "File not exists";
    } else {
        QTextStream in(&file);
        QTextStream out(&file_2);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList<QStandardItem *> standardItemsList;
            for (QString item : line.split(";")) {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
            out << standardItemsList;
        }
        file.close();
        file_2.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete csvModel;
}

void MainWindow::on_pushButton_5_clicked()
{
    if (ui->lineEdit->text().toInt() > 0 && ui->lineEdit_2->text().toInt() > 0) {
        int new_row_count = ui->lineEdit->text().toInt();
        int new_col_count = ui->lineEdit_2->text().toInt();

        QStandardItemModel* current_model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
        if (!current_model) {
            current_model = new QStandardItemModel(new_row_count, new_col_count, this);
            ui->tableView->setModel(current_model);
        } else {
            current_model->setRowCount(new_row_count);
            current_model->setColumnCount(new_col_count);
        }

        for (int i = 0; i < new_row_count; ++i) {
            for (int j = 0; j < new_col_count; ++j) {
                if (!current_model->item(i, j)) {
                    current_model->setItem(i, j, new QStandardItem());
                }
            }
        }


        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    } else {
        throw "Не удовлетворяет условиям";
    }
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui -> lineEdit -> setText(arg1);
}


void MainWindow::on_lineEdit_2_textEdited(const QString &arg2)
{
    ui -> lineEdit_2 -> setText(arg2);
}

