#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->dateEdit2->setDate(QDate::currentDate());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CalculateButton_clicked()
{
    QDate currentDate = QDate::currentDate();
    QDate date1 = ui->dateEdit1->date();
    QDate date2 = ui->dateEdit2->date();
    int daysFromCurrent = qAbs(currentDate.daysTo(date1));
    int days = qAbs(date1.daysTo(date2));

    ui->labelNumDays->setText(QString("Число дней со дня Рождения: %1").arg(days));

    double physical = 100 * sin(2 * M_PI * daysFromCurrent / 23);
    double emotional = 100 * sin(2 * M_PI * daysFromCurrent / 28);
    double intellectual = 100 * sin(2 * M_PI * daysFromCurrent / 33);

    ui->labelPhysical->setText(QString("Физический: %1").arg(physical));
    ui->labelEmotional->setText(QString("Эмоциональный: %1").arg(emotional));
    ui->labelIntellectual->setText(QString("Интеллектуальный: %1").arg(intellectual));

    QPixmap *pixmap = new QPixmap(781, 291);
    pixmap->fill(Qt::white);
    QPainter painter(pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    int centerX = pixmap->width() / 2;
    int centerY = pixmap->height() / 2;
    painter.drawLine(0, centerY, pixmap->width(), centerY);
    painter.drawLine(centerX, 0, centerX, pixmap->height());

    QPoint point;
    for (double i = -daysFromCurrent / 60; i < daysFromCurrent / 60; i += 0.01) {
        physical = 100 * sin(2 * M_PI * (i + daysFromCurrent) / 23);
        emotional = 100 * sin(2 * M_PI * (i + daysFromCurrent) / 28);
        intellectual = 100 * sin(2 * M_PI * (i + daysFromCurrent) / 33);

        QPen linepen(Qt::red);
        linepen.setWidth(3);
        painter.setPen(linepen);
        point.setX(centerX + i * 10);
        point.setY(centerY - physical);
        painter.drawPoint(point);

        linepen.setColor(Qt::blue);
        painter.setPen(linepen);
        point.setY(centerY - emotional);
        painter.drawPoint(point);

        linepen.setColor(QColor(64, 38, 52));
        painter.setPen(linepen);
        point.setY(centerY - intellectual);
        painter.drawPoint(point);
    }

    for (int j=-width()/30; j <= width()/30; j++){
        if(j == 0){
            painter.save();
            QPen linepen(Qt::black);
            linepen.setWidth(3);
            painter.setPen(linepen);
            QFont font = painter.font();
            font.setPointSize(10);
            painter.setFont(font);
            painter.drawLine(j*30,-20, j*30,20);
            painter.rotate(90);
            QString date= ui->dateEdit2->date().addDays(-j).toString();
            painter.drawText(10, j*30, date);
            painter.restore();
        }
        else{

            painter.drawLine(j*30,-10, j*30,10);

            painter.save();
            painter.rotate(90);
            QString date= ui->dateEdit2->date().addDays(-j).toString();
            painter.drawText(10, j*30, date);
            painter.restore();
        }
    }
    painter.end();
    ui->labelGraphic->setPixmap(*pixmap);
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "", tr("Текстовые файлы (*.txt);;Все файлы (*)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "Date 1: " << ui->dateEdit1->date().toString("dd.MM.yyyy") << "\n";
            out << "Date 2: " << ui->dateEdit2->date().toString("dd.MM.yyyy") << "\n";
            int numberOfDays = ui->dateEdit1->date().daysTo(ui->dateEdit2->date());
            out << "Number of days between: " << abs(numberOfDays) << "\n";
            file.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Ошибочка"), tr("Не могу сохранить файл"));
        }
    }
        else
        {
            QMessageBox::information(this, tr("Информация"), tr("Сохрание отменено"));
        }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("Текстовые файлы (*.txt);;Все файлы (*)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QString line;
            while (!in.atEnd())
            {
                line = in.readLine();
                if (line.startsWith("Дата 1: "))
                {
                    ui->dateEdit1->setDate(QDate::fromString(line.mid(8), "dd.MM.yyyy"));
                }
                else if (line.startsWith("Дата 2: "))
                {
                    ui->dateEdit2->setDate(QDate::fromString(line.mid(8), "dd.MM.yyyy"));
                }
                else if (line.startsWith("Число дней между: "))
                {
                    int numberOfDays = line.mid(24).toInt();
                }
            }
            file.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Ошибка"), tr("Не могу открыть файл"));
        }
    }
}
