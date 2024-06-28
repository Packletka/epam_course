#ifndef EASYAZIAVA_H
#define EASYAZIAVA_H

#include <QLabel>
#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class easyAziava;
}

class easyAziava : public QDialog
{
    Q_OBJECT

public:
    void moveLabel();
    explicit easyAziava(QWidget *parent = nullptr);
    ~easyAziava();

private:
    int numClicks = 0;
    int deltaX = 1; // Инициализируем deltaX значением по умолчанию
    int deltaY = 1; // Инициализируем deltaY значением по умолчанию
    void mousePressEvent(QMouseEvent *event) override;
    QTimer *timer;
    void hideAziava(const QVariant &value);
    Ui::easyAziava *ui;
};

#endif // EASYAZIAVA_H
