#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QPushButton>
#include "session.h"

class Dashboard : public QWidget
{
    Q_OBJECT
public:
    explicit Dashboard(QWidget *parent = nullptr);

private slots:
    void createSession();
    void joinSession();
    void endSession();

private:
    QPushButton *btn_createSession;
    QPushButton *btn_joinSession;
    QPushButton *btn_endSession = nullptr;
    Session *currentSession = nullptr;
};

#endif // DASHBOARD_H
