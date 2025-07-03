#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QString>
#include <memory>
#include "user.h"
#include "authmanager.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget: public QWidget {
    Q_OBJECT

public:
    explicit LoginWidget(std::shared_ptr<AuthManager> auth , QWidget *parent = nullptr);
   // ~LoginWidget();

signals:
    void loginSuccessful(QString username , QString password);

private slots:
    void onloginButtonclicked();

private:
    std::shared_ptr<AuthManager> authManager;
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    QPushButton* loginButton;

};

#endif // LOGINWIDGET_H
