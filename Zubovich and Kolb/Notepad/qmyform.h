#ifndef QMYFORM_H
#define QMYFORM_H

#include <QMainWindow>
#include <QMenu>
#include <QtWidgets>
#include "qworkform.h"

class QMyForm : public QMainWindow
{
    Q_OBJECT

public:
    QMyForm(QWidget *parent = nullptr);
    ~QMyForm();

public slots:
    void slotInfo();
    void slotChangeTitle(const QString& str);
};
#endif // QMYFORM_H
