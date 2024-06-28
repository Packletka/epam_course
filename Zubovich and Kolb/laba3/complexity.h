#ifndef COMPLEXITY_H
#define COMPLEXITY_H

#include <QDialog>

namespace Ui {
class Complexity;
}

class Complexity : public QDialog
{
    Q_OBJECT

public:
    // Easy mode
    void onEasyButtonClicked();

    // Medium mode
    void onMediumButtonClicked();

    // Insane mode
    void onInsaneButtonClicked();

    explicit Complexity(QWidget *parent = nullptr);
    ~Complexity();

private:
    Ui::Complexity *ui;
};

#endif // COMPLEXITY_H
