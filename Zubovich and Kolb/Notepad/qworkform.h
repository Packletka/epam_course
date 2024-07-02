#ifndef QWORKFORM_H
#define QWORKFORM_H

#include <QTextEdit>
#include <QWidget>

class QWorkForm : public QTextEdit
{
    Q_OBJECT
public:
    QWorkForm(QWidget* parent = nullptr);

private:
    QString filename;

signals:
    void ChangeTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};

#endif // QWORKFORM_H
