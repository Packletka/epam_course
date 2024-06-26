#ifndef WATCHES_H
#define WATCHES_H

#include "ui_watches.h"
#include <QTimer>
#include <QWidget>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QImage>
#include <QPixmap> // Включите заголовок для QPixmap

namespace Ui {
class Watches;
}

class Watches : public QDialog
{
    Q_OBJECT

public:
    explicit Watches(QWidget *parent = nullptr);
    ~Watches();

private:
    Ui::Watches *ui;
    int currentImageIndex = 0;

    QTimer *timer = new QTimer(this);
    void paintEvent(QPaintEvent *event);
    void updateClock();
    void drawHand(QPainter &painter, int centerX, int centerY, int length, int angle, QColor color);

    void showEvent(QShowEvent *event);
};

#endif // WATCHES_H
