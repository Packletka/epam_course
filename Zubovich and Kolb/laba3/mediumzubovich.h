#ifndef MEDIUMZUBOVICH_H
#define MEDIUMZUBOVICH_H

#include <QLabel>
#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class mediumZubovich;
}

class mediumZubovich : public QDialog
{
    Q_OBJECT

public:
    void moveLabel();
    explicit mediumZubovich(QWidget *parent = nullptr);
    ~mediumZubovich();

private:
    int numClicks = 0;
    int deltaX = 1; // Инициализируем deltaX значением по умолчанию
    int deltaY = 1; // Инициализируем deltaY значением по умолчанию
    void mousePressEvent(QMouseEvent *event) override;
    QTimer *timer;
    void hideZubovich(const QVariant &value);
    Ui::mediumZubovich *ui;
};

#endif // MEDIUMZUBOVICH_H
