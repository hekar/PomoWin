#ifndef TIMERSLOTS_H
#define TIMERSLOTS_H

#include <QObject>

class QTimer;

const int DEFAULT_FLASHES = 25;

class TimerSlots : public QObject
{
    Q_OBJECT
public:
    explicit TimerSlots(QObject *parent,
                        QObject *timer,
                        QTimer *countdown,
                        QTimer *flash);

signals:

public slots:
    void startTask();
    void startLongBreak();
    void startShortBreak();
    void stopCountdown();

    void updateTimer();
    void flashTimer();
    void closeApplication();

private:
    void startCountdown(int remainingMinutes, const QColor& borderColor);
    void startFlashing();
    void updateCountdownDisplay();

    int remainingMinutes;
    int flashesRemaining;
    QObject *timer;
    QTimer *countdown;
    QTimer *flash;
};

#endif // TIMERSLOTS_H
