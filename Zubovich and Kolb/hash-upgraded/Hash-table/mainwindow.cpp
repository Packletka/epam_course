#include "mainwindow.h"
#include "qmenu.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

int HashFunctionHorner(const QString& s, int table_size, const int key)
{
    int hash_result = 0;
    for (int i = 0; i != s.size(); ++i)
    {
        hash_result = (key * hash_result + s[i].unicode()) % table_size;
    }
    hash_result = (hash_result * 2 + 1) % table_size;
    return hash_result;
}

struct HashFunction1
{
    int operator()(const QString& s, int table_size) const
    {
        return HashFunctionHorner(s, table_size, table_size - 1);
    }
};

struct HashFunction2
{
    int operator()(const QString& s, int table_size) const
    {
        return HashFunctionHorner(s, table_size, table_size + 1);
    }
};

struct Node
{
    QString key;
    QString title;
    QString author;
    bool state;
    Node(const QString& k, const QString& t, const QString& a) : key(k), title(t), author(a), state(true) {}
    QString& getTitle() {return title;}
    QString& getAuthor() {return author;}
};



class HashTable
{
    static const int default_size = 8;
    constexpr static const double rehash_size = 0.75;
    Node** arr;
    int size;
    int buffer_size;
    int size_all_non_nullptr;

    void Resize()
    {
        int past_buffer_size = buffer_size;
        buffer_size *= 2;
        size_all_non_nullptr = 0;
        size = 0;
        Node** arr2 = new Node * [buffer_size];
        for (int i = 0; i < buffer_size; ++i)
            arr2[i] = nullptr;
        std::swap(arr, arr2);
        for (int i = 0; i < past_buffer_size; ++i)
        {
            if (arr2[i] && arr2[i]->state)
                Add(arr2[i]->key, arr2[i]->title, arr2[i]->author);
        }
        for (int i = 0; i < past_buffer_size; ++i)
            if (arr2[i])
                delete arr2[i];
        delete[] arr2;
    }

    void Rehash()
    {
        size_all_non_nullptr = 0;
        size = 0;
        Node** arr2 = new Node * [buffer_size];
        for (int i = 0; i < buffer_size; ++i)
            arr2[i] = nullptr;
        std::swap(arr, arr2);
        for (int i = 0; i < buffer_size; ++i)
        {
            if (arr2[i] && arr2[i]->state)
                Add(arr2[i]->key, arr2[i]->title, arr2[i]->author);
        }
        for (int i = 0; i < buffer_size; ++i)
            if (arr2[i])
                delete arr2[i];
        delete[] arr2;
    }

public:
    HashTable()
    {
        buffer_size = default_size;
        size = 0;
        size_all_non_nullptr = 0;
        arr = new Node*[buffer_size];
        for (int i = 0; i < buffer_size; ++i)
            arr[i] = nullptr;
    }
    ~HashTable()
    {
        for (int i = 0; i < buffer_size; ++i)
            if (arr[i])
                delete arr[i];
        delete[] arr;
    }

    bool Add(const QString& value, const QString& t, const QString& a, const HashFunction1& hash1 = HashFunction1(), const HashFunction2& hash2 = HashFunction2())
    {
        if (size + 1 > int(rehash_size * buffer_size))
            Resize();
        else if (size_all_non_nullptr > 2 * size)
            Rehash();
        int h1 = hash1(value, buffer_size);
        int h2 = hash2(value, buffer_size);
        int i = 0;
        int first_deleted = -1;
        while (arr[h1] != nullptr && i < buffer_size)
        {
            if (arr[h1]->key == value && arr[h1]->state)
                return false;
            if (!arr[h1]->state && first_deleted == -1)
                first_deleted = h1;
            h1 = (h1 + h2) % buffer_size;
            ++i;
        }
        if (first_deleted == -1)
        {
            arr[h1] = new Node(value, t, a);
            ++size_all_non_nullptr;
        }
        else
        {
            arr[first_deleted]->key = value;
            arr[first_deleted]->title = t;
            arr[first_deleted]->author = a;
            arr[first_deleted]->state = true;
        }
        ++size;
        return true;
    }

    void Remove(const QString& value, const HashFunction1& hash1 = HashFunction1(), const HashFunction2& hash2 = HashFunction2())
    {
        int h1 = hash1(value, buffer_size);
        int h2 = hash2(value, buffer_size);
        int i = 0;
        while (arr[h1] != nullptr && i < buffer_size)
        {
            if (arr[h1]->key == value && arr[h1]->state)
            {
                arr[h1]->state = false;
                --size;
                return;
            }
            h1 = (h1 + h2) % buffer_size;
            ++i;
        }
        return;
    }

    bool Contains(const QString& value, const HashFunction1& hash1 = HashFunction1(), const HashFunction2& hash2 = HashFunction2())
    {
        int h1 = hash1(value, buffer_size);
        int h2 = hash2(value, buffer_size);
        int i = 0;
        while (arr[h1] != nullptr && i < buffer_size)
        {
            if (arr[h1]->key == value && arr[h1]->state)
                return true;
            h1 = (h1 + h2) % buffer_size;
            ++i;
        }
        return false;
    }

    Node* Find(const QString& value, const HashFunction1& hash1 = HashFunction1(), const HashFunction2& hash2 = HashFunction2())
    {
        int h1 = hash1(value, buffer_size);
        int h2 = hash2(value, buffer_size);
        int i = 0;
        while (arr[h1] != nullptr && i < buffer_size)
        {
            if (arr[h1]->key == value && arr[h1]->state)
                return arr[h1];
            h1 = (h1 + h2) % buffer_size;
            ++i;
        }
        return nullptr;
    }

    QList<QString> keys()
    {
        QList<QString> list;
        int i = 0;
        while (i != buffer_size)
        {
            ++i;
            if (arr[i] != nullptr && arr[i]->state)
                list.append(arr[i]->key);
        }
        return list;
    }
};


class Book {
public:
    QString isbn;
    QString title;
    QString author;

    Book() {}

    Book(const QString &isbn, const QString &title, const QString &author) :
        isbn(isbn), title(title), author(author) {}

    QString toString() const {
        return isbn + ";" + title + ";" + author;
    }

    void fromString(const QString &str) {
        QStringList parts = str.split(';');
        isbn = parts[0];
        title = parts[1];
        author = parts[2];
    }
};

HashTable table;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    srand(time(NULL)/*QDateTime::currentMSecsSinceEpoch()*/);
    ui->setupUi(this);
    QLabel *isbnLabel = new QLabel("ISBN:");
    isbnLineEdit = new QLineEdit;
    QLabel *titleLabel = new QLabel("Title:");
    titleLineEdit = new QLineEdit;
    QLabel *authorLabel = new QLabel("Author:");
    authorLineEdit = new QLineEdit;
    addButton = new QPushButton("Add book");
    deleteButton = new QPushButton("Remove book");
    searchButton = new QPushButton("Search book");
    showAllButton = new QPushButton("View all");
    resultLabel = new QLabel("");
    bookTable = new QTableWidget;
    QMenu* file = new QMenu("&File");
    file->addAction("&Load", this, SLOT(loadBooks()));
    file->addAction("&Save", this, SLOT(saveBooks()));
    file->addSeparator();
    file->addAction("&Quit", qApp, SLOT(quit()));
    menuBar()->addMenu(file);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(isbnLabel, isbnLineEdit);
    formLayout->addRow(titleLabel, titleLineEdit);
    formLayout->addRow(authorLabel, authorLineEdit);
    QHBoxLayout *buttonLayout1 = new QHBoxLayout;
    buttonLayout1->addWidget(addButton);
    buttonLayout1->addWidget(deleteButton);
    QHBoxLayout *buttonLayout2 = new QHBoxLayout;
    buttonLayout2->addWidget(searchButton);
    buttonLayout2->addWidget(showAllButton);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout1);
    mainLayout->addLayout(buttonLayout2);
    mainLayout->addWidget(resultLabel);
    mainLayout->addWidget(bookTable);
    ui->centralwidget->setLayout(mainLayout);

    bookTable->setColumnCount(3);
    QStringList headers = {"ISBN", "Title", "Author"};
    bookTable->setHorizontalHeaderLabels(headers);
    bookTable->horizontalHeader()->setStretchLastSection(true);
    bookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addBook);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteBook);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::searchBook);
    connect(showAllButton, &QPushButton::clicked, this, &MainWindow::showAllBooks);

    int key_1;
    int key_2;
    QString ISBN;
    QString avtor;
    QString nazva;
    // QRandomGenerator generator;
    for (int i = 0; i < 50; ++i)
    {
        key_1 = rand()/*generator.generate()*/ % 100000;
        key_2 = rand()/*generator.generate()*/ % 100000;
        ISBN = QString::number(key_1)+"-"+QString::number(key_2);
        nazva = "Book№"+QString::number(i);
        avtor = "Author№"+QString::number(i);
        table.Add(ISBN, nazva, avtor);
    }

}

void MainWindow::addBook() {
    QString isbn = isbnLineEdit->text();
    QString title = titleLineEdit->text();
    QString author = authorLineEdit->text();

    if (isbn.isEmpty() || title.isEmpty() || author.isEmpty()) {
        QMessageBox::information(this, "Error", "No full information");
        return;
    }

    if (table.Contains(isbn)) {
        QMessageBox::information(this, "Error", "ISBN already exist");
        return;
    }

    table.Add(isbn, title, author);
    resultLabel->setText("Added");

    isbnLineEdit->clear();
    titleLineEdit->clear();
    authorLineEdit->clear();

}

void MainWindow::deleteBook() {
    QString isbn = isbnLineEdit->text();

    if (isbn.isEmpty()) {
        QMessageBox::information(this, "Error", "Enter ISBN");
        return;
    }

    if (!table.Contains(isbn)) {
        QMessageBox::information(this, "Error", "ISBN not found");
        return;
    }

    table.Remove(isbn);
    resultLabel->setText("Removed");

    isbnLineEdit->clear();

}

void MainWindow::searchBook() {
    QString isbn = isbnLineEdit->text();

    if (isbn.isEmpty()) {
        QMessageBox::information(this, "Error", "Enter ISBN");
        return;
    }

    if (table.Contains(isbn)) {
        Node node = *table.Find(isbn);
        Book book;
        book.isbn = isbn;
        book.title = node.getTitle();
        book.author = node.getAuthor();
        resultLabel->setText("Title: " + book.title + ", Author: " + book.author);
    } else {
        resultLabel->setText("ISBN not found");
    }
}

void MainWindow::showAllBooks() {
    bookTable->setRowCount(0);

    int row = 0;
    foreach (QString key, table.keys()) {
        Node node = *table.Find(key);
        Book book;
        book.isbn = key;
        book.title = node.getTitle();
        book.author = node.getAuthor();
        bookTable->insertRow(row);
        bookTable->setItem(row, 0, new QTableWidgetItem(key));
        bookTable->setItem(row, 1, new QTableWidgetItem(book.title));
        bookTable->setItem(row, 2, new QTableWidgetItem(book.author));
        row++;
    }
}

void MainWindow::saveBooks() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save", "", "Txt files (*.txt)");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        foreach (QString key, table.keys()) {
            Node node = *table.Find(key);
            Book book;
            book.isbn = key;
            book.title = node.getTitle();
            book.author = node.getAuthor();
            out << book.toString() << '\n';
        }
        file.close();
        resultLabel->setText("Saved");
    } else {
        QMessageBox::information(this, "Error", "Not saved");
    }
}

void MainWindow::loadBooks() {
    // QString fileName = QFileDialog::getOpenFileName(this, "Load", "", "Txt files (*.txt)");
    // if (fileName.isEmpty()) {
    //     return;
    // }

    // QFile file(fileName);
    // if (file.open(QIODevice::ReadOnly)) {
    //     QTextStream in(&file);
    //     bookHash.clear();
    //     while (!in.atEnd()) {
    //         QString line = in.readLine();
    //         Book book;
    //         book.fromString(line);
    //         bookHash[book.isbn] = book;
    //     }
    //     file.close();
    //     resultLabel->setText("Loaded");
    //     updateTable();
    // } else {
    //     QMessageBox::warning(this, "Error", "Not load");
    // }
}

void MainWindow::updateTable() {
    showAllBooks();
    resultLabel->setText("");
}
