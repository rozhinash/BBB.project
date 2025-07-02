#include "dashboard.h"
#include "sessionmanager.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

Dashboard::Dashboard(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("داشبورد");

    QVBoxLayout *layout = new QVBoxLayout(this);

    btn_createSession = new QPushButton("ایجاد جلسه", this);
    btn_joinSession = new QPushButton("ورود به جلسه", this);

    layout->addWidget(btn_createSession);
    layout->addWidget(btn_joinSession);

    connect(btn_createSession, &QPushButton::clicked, this, &Dashboard::createSession);
    connect(btn_joinSession, &QPushButton::clicked, this, &Dashboard::joinSession);
}

void Dashboard::createSession()
{
    if (currentSession && currentSession->isActive()) {
        QMessageBox::warning(this, "هشدار", "یک جلسه در حال حاضر فعال است!");
        return;
    }

    Session* session = SessionManager::getInstance().createSession();
    currentSession = session;

    QMessageBox::information(this, "ایجاد جلسه", "جلسه با کد " + session->getSessionId() + " ایجاد شد.");

    if (!btn_endSession) {
        btn_endSession = new QPushButton("پایان جلسه", this);
        layout()->addWidget(btn_endSession);
        connect(btn_endSession, &QPushButton::clicked, this, &Dashboard::endSession);
    }

    btn_endSession->setEnabled(true);
    btn_endSession->show();
}

void Dashboard::joinSession()
{
    bool ok;
    QString code = QInputDialog::getText(this, "ورود به جلسه", "کد جلسه را وارد کنید:", QLineEdit::Normal, "", &ok);

    if (!ok || code.isEmpty()) return;

    Session* session = SessionManager::getInstance().findSession(code);
    if (session) {
        QMessageBox::information(this, "موفق", "وارد جلسه با کد " + code + " شدید.");
    } else {
        QMessageBox::warning(this, "خطا", "جلسه‌ای با این کد پیدا نشد یا منقضی شده است.");
    }
}

void Dashboard::endSession()
{
    if (currentSession && currentSession->isActive()) {
        currentSession->endSession();
        QMessageBox::information(this, "پایان جلسه", "جلسه پایان یافت.");
        btn_endSession->setEnabled(false);
    }
}
