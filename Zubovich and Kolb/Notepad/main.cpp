#include "qmyform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMyForm w;
    w.show();
    w.resize(800, 600);
    return a.exec();
}
