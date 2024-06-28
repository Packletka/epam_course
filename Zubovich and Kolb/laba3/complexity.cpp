#include "complexity.h"
#include "ui_complexity.h"
#include "easyaziava.h"
#include "mediumzubovich.h"
#include "insanekarpa.h"


Complexity::Complexity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Complexity)
{
    ui->setupUi(this);

    connect(ui->easyMode, &QPushButton::clicked, this, &Complexity::onEasyButtonClicked);
    connect(ui->mediumMode, &QPushButton::clicked, this, &Complexity::onMediumButtonClicked);
    connect(ui->insaneMode, &QPushButton::clicked, this, &Complexity::onInsaneButtonClicked);
}


void Complexity::onEasyButtonClicked() {
    easyAziava *battleWindow = new easyAziava();
    this->close();

    battleWindow->show();
}


void Complexity::onMediumButtonClicked() {
    mediumZubovich *battleWindow = new mediumZubovich();
    this->close();

    battleWindow->show();
}


void Complexity::onInsaneButtonClicked() {
    insaneKarpa *battleWindow = new insaneKarpa();
    this->close();

    battleWindow->show();
}


Complexity::~Complexity()
{
    delete ui;
}
