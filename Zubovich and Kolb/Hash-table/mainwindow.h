#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QString>
#include <QHash>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addBook();
    void deleteBook();
    void searchBook();
    void showAllBooks();
    void saveBooks();
    void loadBooks();

private:
    void updateTable();

    QLineEdit *isbnLineEdit;
    QLineEdit *titleLineEdit;
    QLineEdit *authorLineEdit;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *searchButton;
    QPushButton *showAllButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QLabel *resultLabel;
    QTableWidget *bookTable;
};

#endif
