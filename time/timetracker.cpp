#include "timetracker.h"
#include <QMessageBox>
#include <QApplication>

TimeTracker::TimeTracker(QWidget *parent) : QWidget(parent), warningGiven(false) {
    startTime = QTime::currentTime();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimeTracker::checkTime);
    timer->start(1000);
}

void TimeTracker::checkTime() {
    int elapsed = startTime.secsTo(QTime::currentTime());

    const int threeHours = 3 * 60 * 60;    // 10800 seconds
    const int fifteenMinutes = 15 * 60;    // 900 seconds

    if (elapsed >= threeHours) {
        QMessageBox::information(this, "زمان جلسه", "جلسه تموم شد و کلاس بسته می‌شود.");
        QApplication::quit();
    } else if (elapsed >= (threeHours - fifteenMinutes) && !warningGiven) {
        QMessageBox::warning(this, "هشدار زمان", "کلاس تا ۱۵ دقیقه دیگه بسته می‌شود.");
        warningGiven = true;
    }
}
