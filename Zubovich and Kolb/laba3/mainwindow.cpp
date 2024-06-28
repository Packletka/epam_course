#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complexity.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Кнопка "Start game"
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);

    // Кнопка "Exit"
    connect(ui->exitButton, &QPushButton::clicked, this, &QWidget::close);
}


void MainWindow::onStartButtonClicked() {
    // Создание нового окна
    Complexity *complexityWindow = new Complexity();
    this->close();

    // Показ нового окна
    complexityWindow->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}
