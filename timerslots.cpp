#include <QObject>
#include <QQuickItem>
#include <QDebug>
#include <QTimer>
#include <QColor>
#include "timerslots.h"

TimerSlots::TimerSlots(QObject *parent,
                       QObject *timer,
                       QTimer *countdown,
                       QTimer *flash) : QObject(parent)
{
    this->remainingMinutes = 0;
    this->timer = timer;
    this->countdown = countdown;
    this->flash = flash;
}

void TimerSlots::startTask()
{
    startCountdown(25, QColor("#a00"));
}

void TimerSlots::startLongBreak()
{
    startCountdown(15, QColor("#0a0"));
}

void TimerSlots::startShortBreak()
{
    startCountdown(5, QColor("#00a"));
}

void TimerSlots::stopCountdown()
{
    this->countdown->stop();
}

void TimerSlots::updateTimer()
{
    if (--remainingMinutes <= 0)
    {
        countdown->stop();
        startFlashing();
    }

    updateCountdownDisplay();
}

void TimerSlots::flashTimer()
{
    qDebug() << "Flash Timer";
}

void TimerSlots::closeApplication()
{
  QCoreApplication::quit();
}

void TimerSlots::startCountdown(int remaining, const QColor& borderColor)
{
    this->remainingMinutes = remaining;
    countdown->start();
    updateCountdownDisplay();
}

void TimerSlots::startFlashing()
{
}

void TimerSlots::updateCountdownDisplay()
{
    qDebug() << "Minutes remaining" << remainingMinutes;
    timer->setProperty("text", QString::number(remainingMinutes));
}
