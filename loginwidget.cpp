#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QMessageBox>
#include "admin.h"
#include "adminwidget.h"
#include "regularuser.h"
#include "regularuserwidget.h"
#include "user.h"
#include <QVBoxLayout>


LoginWidget::LoginWidget(std::shared_ptr<AuthManager> auth , QWidget *parent)
    : QWidget(parent),  authManager(auth)
{
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("ورود", this);

    auto layout = new QVBoxLayout(this);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton , &QPushButton::clicked,this , &LoginWidget::onloginButtonclicked);
}
void LoginWidget::onloginButtonclicked()
{
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text().trimmed();

    emit loginSuccessful(username , password);
}



