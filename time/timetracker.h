#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#include <QWidget>
#include <QTime>
#include <QTimer>

class TimeTracker : public QWidget {
    Q_OBJECT

public:
    explicit TimeTracker(QWidget *parent = nullptr);

private slots:
    void checkTime();

private:
    QTime startTime;
    QTimer *timer;
    bool warningGiven;
};

#endif // TIMETRACKER_H
