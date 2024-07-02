#include <QCoreApplication>
#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
#include <QFile>


class TextEditor : public QMainWindow {
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Simple Text Editor");

        textEdit = new QTextEdit(this);
        setCentralWidget(textEdit);

        createMenu();
    }

private slots:
    void saveTextAs() {
        QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << textEdit->toPlainText();
                file.close();
            }
        }
    }

    void loadText() {
        QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                textEdit->setPlainText(in.readAll());
                file.close();
            }
        }
    }

    void saveBinary() {
        QString fileName = QFileDialog::getSaveFileName(this, "Save Binary File", "", "Binary Files (*.bin)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly)) {
                QDataStream out(&file);
                out << textEdit->toPlainText();
                file.close();
            }
        }
    }

    void loadBinary() {
        QString fileName = QFileDialog::getOpenFileName(this, "Open Binary File", "", "Binary Files (*.bin)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly)) {
                QDataStream in(&file);
                QString data;
                in >> data;
                textEdit->setPlainText(data);
                file.close();
            }
        }
    }

private:
    void createMenu() {
        QMenu *fileMenu = menuBar()->addMenu("File");

        QAction *saveTextAction = new QAction("Save Text As...", this);
        connect(saveTextAction, &QAction::triggered, this, &TextEditor::saveTextAs);
        fileMenu->addAction(saveTextAction);

        QAction *loadTextAction = new QAction("Load Text", this);
        connect(loadTextAction, &QAction::triggered, this, &TextEditor::loadText);
        fileMenu->addAction(loadTextAction);

        QAction *saveBinaryAction = new QAction("Save Binary...", this);
        connect(saveBinaryAction, &QAction::triggered, this, &TextEditor::saveBinary);
        fileMenu->addAction(saveBinaryAction);

        QAction *loadBinaryAction = new QAction("Load Binary", this);
        connect(loadBinaryAction, &QAction::triggered, this, &TextEditor::loadBinary);
        fileMenu->addAction(loadBinaryAction);
    }

    QTextEdit *textEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TextEditor editor;
    editor.show();

    return app.exec();
}

#include "main.moc"
