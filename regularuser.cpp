#include "regularuser.h"
#include <QDebug>
#include <QFormLayout>
#include "../Role/role.h"
//RegularUser::RegularUser(QWidget *parent)
//: User(parent) {}

RegularUser::RegularUser(int userID , QString name, QString lastname, QString password, Role level, QWidget *parent)
    :User( userID ,name, lastname, password, level , parent) {}

void RegularUser::setupUI() {
    User::setupUI(); // فرم توی یوزر رو اجرا کن

    // اضافه کردن دکمهٔ تاریخچه
    btn_viewHistory = new QPushButton(" نمایش تاریخچه جلسات", this);
    QFormLayout* formlayout = qobject_cast<QFormLayout*>(this->layout());
    if (formlayout)
        formlayout->addRow(btn_viewHistory);

    connect(btn_viewHistory, &QPushButton::clicked, this, &RegularUser::showSessionHistory);
}


void RegularUser::joinSession(const QString& sessionID) {
    if (userLevel != Role::Regular){
        qDebug()<<"امکان جوین به جلسه نیست";
        return;
    }

    if (!sessionHistory.contains(sessionID)) {
        sessionHistory.append(sessionID);
        qDebug() << " کاربر جوین شد به جلسه:" << sessionID;
    }
}

void RegularUser::leaveSession(const QString& sessionID) {
    if (userLevel != Role::Regular){
        qDebug() <<"امکان ترک جلسه نیست";
        return;
    }

    if(sessionHistory.removeAll(sessionID) > 0){
        qDebug() << " کاربر ترک جلسه کرد:" << sessionID;
    }else {
        qDebug() <<"جلسه ای با این کد در لیست کاربر نیست";
    }
}

QStringList RegularUser::getSessionHistory() const {
    return sessionHistory;
}

bool RegularUser::login(const QString& name, const QString& lastname, const QString& password) {
    return (this-> name == name && this ->lastname == lastname && this->password == password);
}



void RegularUser::showSessionHistory() {
    if (!sessionHistoryListWidget) {
        sessionHistoryListWidget = new QListWidget;
        sessionHistoryListWidget->setWindowTitle("تاریخچه جلسات");
        sessionHistoryListWidget->resize(300, 200);
    }

    sessionHistoryListWidget->clear();
    for (const QString& session : sessionHistory) {
        sessionHistoryListWidget->addItem(" " + session);
    }
    sessionHistoryListWidget->show();
}

