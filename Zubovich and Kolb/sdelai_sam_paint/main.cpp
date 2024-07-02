#include "mainwindow.h"

#include <QApplication>

int main(int argv, char *args[])
{
    Q_INIT_RESOURCE(diagramscene);
#ifdef Q_OS_ANDROID
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argv, args);
    MainWindow mainWindow;
    mainWindow.setGeometry(100, 100, 800, 500);
    mainWindow.show();

    return app.exec();
}
