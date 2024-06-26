#include <QTimer>
#include <QCursor>
#include <QWidget>
#include <QPoint>
#include <QPropertyAnimation>
#include "easyaziava.h"
#include "ui_easyaziava.h"


easyAziava::easyAziava(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::easyAziava)
{
    ui->setupUi(this);

    // Задание значения progressBar
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(100);

    QTimer *timer = new QTimer(this);
    timer->setInterval(2); // Интервал обновления в миллисекундах
    connect(timer, &QTimer::timeout, this, &easyAziava::moveLabel);

    timer->start();

    QCursor cursor = QCursor(QPixmap(":/files_qrc/bita.png"));
    this->setCursor(cursor);

    numClicks = 0;
}


void easyAziava::mousePressEvent(QMouseEvent *event)
{
    QString filePaths[3] = {
        ":/files_qrc/aziava_with_blood_1.png",
        ":/files_qrc/aziava_with_blood_2.png",
        ":/files_qrc/aziava_with_blood_3.png"
    };

    if (event->button() == Qt::LeftButton) {
        if (ui->aziava->geometry().contains(event->pos())) {
            numClicks++;
            double health = 100 * (3 - numClicks) / 3;
            ui->progressBar->setValue(health);

            QPixmap newPixmap(filePaths[numClicks - 1]);

            ui->aziava->setPixmap(newPixmap);

            if (numClicks >= 3) {
                QLabel *hearse = new QLabel(this);
                hearse->setPixmap(QPixmap(":/files_qrc/hearse.png"));
                hearse->setFixedSize(QSize(180, 73));

                hearse->move(this->width() - hearse->width(), ui->aziava->geometry().y());

                QPropertyAnimation *animation = new QPropertyAnimation(hearse, "geometry");
                animation->setDuration(2500); // Время анимации в миллисекундах
                animation->setStartValue(hearse->geometry());
                animation->setEndValue(QRect(ui->aziava->geometry())); // Устанавливаем конечные координаты такие же, как у aziava
                animation->setEasingCurve(QEasingCurve::OutQuad);

                hearse->show();

                animation->start();

                // Скрыть aziava после окончания анимации
                connect(animation, &QPropertyAnimation::finished, this, [this, hearse]() {
                    ui->aziava->hide();

                    QPropertyAnimation *animation2 = new QPropertyAnimation(hearse, "geometry");
                    animation2->setDuration(2500); // Время анимации в миллисекундах
                    animation2->setStartValue(hearse->geometry());
                    animation2->setEndValue(QRect(0, hearse->y(), hearse->width(), hearse->height()));
                    animation2->setEasingCurve(QEasingCurve::OutQuad);

                    // Запускаем вторую анимацию
                    animation2->start();

                    // По завершении второй анимации, закрываем окно
                    connect(animation2, &QPropertyAnimation::finished, this, [this]() {
                        close();
                    });
                });
            }
        }
    }
}


void easyAziava::moveLabel()
{
    // Проверка, было ли уже выполнено 3 нажатия
    if (numClicks >= 3) {
        return;
    }

    int currentX = ui->aziava->x();
    int currentY = ui->aziava->y();

    int windowWidth = this->width();
    int windowHeight = this->height();

    int labelWidth = ui->aziava->width();
    int labelHeight = ui->aziava->height();

    int newX = currentX + deltaX;
    int newY = currentY + deltaY;

    if (newX < 0 || newX > windowWidth - labelWidth) {
        deltaX = -deltaX; // Отражаем от стенки
        newX = qBound(0, newX, windowWidth - labelWidth);
    }

    if (newY < 0 || newY > windowHeight - labelHeight) {
        deltaY = -deltaY; // Отражаем от стенки
        newY = qBound(0, newY, windowHeight - labelHeight);
    }

    ui->aziava->move(newX, newY);
}


void easyAziava::hideAziava(const QVariant &value)
{
    QVariant startValue = value.value<QVariantMap>().value("startValue");
    QRect startRect = qvariant_cast<QRect>(startValue);

    QVariant endValue = value.value<QVariantMap>().value("endValue");
    QRect endRect = qvariant_cast<QRect>(endValue);

    // Скрываем aziava, когда hearse будет иметь те же координаты
    if (startRect.x() == endRect.x()) {
        ui->aziava->hide();
    }
}


easyAziava::~easyAziava()
{
    delete ui;
}
