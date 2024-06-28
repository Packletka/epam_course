#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Biorhythms");
    w.show();
    QIcon icon("C:/Qt/Biorr.jpg");
    a.setWindowIcon(icon);
    return a.exec();
}
