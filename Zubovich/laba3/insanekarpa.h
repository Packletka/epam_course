#ifndef INSANEKARPA_H
#define INSANEKARPA_H

#include <QLabel>
#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class insaneKarpa;
}

class insaneKarpa : public QDialog
{
    Q_OBJECT

public:
    void moveLabel();
    explicit insaneKarpa(QWidget *parent = nullptr);
    ~insaneKarpa();

private:
    int numClicks = 0;
    int deltaX = 1; // Инициализируем deltaX значением по умолчанию
    int deltaY = 1; // Инициализируем deltaY значением по умолчанию
    void mousePressEvent(QMouseEvent *event) override;
    QTimer *timer;
    void hideKarpa(const QVariant &value);
    Ui::insaneKarpa *ui;
};

#endif // INSANEKARPA_H
