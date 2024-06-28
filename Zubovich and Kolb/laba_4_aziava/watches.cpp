#include <QTimer>
#include "watches.h"
#include "ui_watches.h"
#include <QPainter>
#include <QDateTime>
#include <QTimeZone>
#include <QPixmap>

Watches::Watches(QWidget *parent) : QDialog(parent), ui(new Ui::Watches)
{
    ui->setupUi(this);

    currentImageIndex = 0; // Initialize current image index

    // Create a timer
    timer = new QTimer(this);

    // Connect the timer's timeout signal to the updateClock slot
    connect(timer, &QTimer::timeout, this, &Watches::updateClock);

    // Start the timer with an interval of 1 second
    timer->start(1000);
}


void Watches::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    // Start the timer only once when the window is shown
    if (!timer->isActive()) {
        timer->start(1000);
    }
}



void Watches::paintEvent(QPaintEvent *event)
{
    QDialog::paintEvent(event);

    // Load the image from the resource file based on the current index
    QStringList imagePaths = {":/resources/chasi_1.jpg", ":/resources/chasi_2.png", ":/resources/chasi_3.png"};
    QPixmap background(imagePaths[currentImageIndex]);

    QPainter painter(this); // Declare the painter object here
    painter.drawPixmap(rect(), background, background.rect());
    painter.setRenderHint(QPainter::Antialiasing);

    // Get the current time in Minsk
    QTimeZone timeZone("Europe/Minsk");
    QDateTime currentDateTime = QDateTime::currentDateTimeUtc();
    currentDateTime.setTimeZone(timeZone);

    // Determine the center of the clock
    int centerX = width() / 2;
    int centerY = height() / 2;

    // Radius of the clock
    int radius = qMin(centerX, centerY) - 10;

    // Draw the hour hand
    int hour = currentDateTime.time().hour();
    int minute = currentDateTime.time().minute();
    int hourAngle = (hour % 12) * 30 + minute / 2;
    drawHand(painter, centerX, centerY, radius * 0.4, hourAngle, QColorConstants::Green);

    // Draw the minute hand
    drawHand(painter, centerX, centerY, radius * 0.6, ((45 + minute) % 60) * 6, QColorConstants::Red);

    // Draw the second hand
    int second = currentDateTime.time().second();
    int secondAngle = second * 6; // Angle in degrees
    drawHand(painter, centerX, centerY, radius * 0.8, secondAngle, QColorConstants::Blue);
}

// Function to draw a hand
void Watches::drawHand(QPainter &painter, int centerX, int centerY, int length, int angle, QColor color)
{
    painter.setPen(QPen(color, 2));
    painter.drawLine(centerX, centerY, centerX + length * qCos(qDegreesToRadians(angle)), centerY + length * qSin(qDegreesToRadians(angle)));
}


void Watches::updateClock()
{
    currentImageIndex = (currentImageIndex + 1) % 3; // Cycling through 3 images
    update();
    QTimer::singleShot(timer->interval(), this, &Watches::updateClock); // Schedule the next update every 1 second
}


Watches::~Watches()
{
    delete ui;
    delete timer;
}
