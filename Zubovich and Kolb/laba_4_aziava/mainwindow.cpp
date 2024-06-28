#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "watches.h"
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *gif = new QLabel(this);
    QMovie *movie = new QMovie(":/resources/100.gif");

    gif->setMovie(movie);
    movie->start();

    setCentralWidget(gif);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, gif]() {
        gif->deleteLater();
        this->close();
        Watches *watchesWindow = new Watches();
        watchesWindow->show();
    });

    timer->setSingleShot(true);
    timer->start(7800);
}


MainWindow::~MainWindow()
{
    delete ui;
}
