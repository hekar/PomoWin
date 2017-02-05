#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>
#include "timerslots.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto context = engine.rootObjects();
    QObject *rootView = context[0];

    QObject *timer = rootView->findChild<QObject *>(QString("timer"));
    QObject *start = rootView->findChild<QObject *>(QString("start"));
    QObject *longBreak = rootView->findChild<QObject *>(QString("long_break"));
    QObject *shortBreak = rootView->findChild<QObject *>(QString("short_break"));
    QObject *close = rootView->findChild<QObject *>(QString("close"));
    QTimer *countdown = new QTimer(&app);
    QTimer *flash = new QTimer(&app);

    TimerSlots timerSlots(&app, timer, countdown, flash);

    QObject::connect(timer, SIGNAL(clicked()),
                      &timerSlots, SLOT(stopCountdown()));
    QObject::connect(start, SIGNAL(clicked()),
                      &timerSlots, SLOT(startTask()));
    QObject::connect(longBreak, SIGNAL(clicked()),
                      &timerSlots, SLOT(startLongBreak()));
    QObject::connect(shortBreak, SIGNAL(clicked()),
                      &timerSlots, SLOT(startShortBreak()));
    QObject::connect(close, SIGNAL(clicked()),
                      &timerSlots, SLOT(closeApplication()));
    QObject::connect(countdown, SIGNAL(timeout()), &timerSlots, SLOT(updateTimer()));
    QObject::connect(flash, SIGNAL(timeout()), &timerSlots, SLOT(flashTimer()));

    auto interval = 1000; // * 60;
    countdown->start(interval);

    return app.exec();
}
