#ifndef REGULARUSER_H
#define REGULARUSER_H
#include "../User/user.h"
#include <QStringList>
#include <QPushButton>
#include <QListWidget>
#include "../Role/role.h"
class RegularUser : public User {
    Q_OBJECT

public:
    explicit RegularUser(QWidget *parent = nullptr);
    RegularUser(int userID ,QString name, QString lastname, QString password, Role level, QWidget *parent = nullptr);

    void joinSession(const QString& sessionID);
    void leaveSession(const QString& sessionID);
    QStringList getSessionHistory() const;
    bool login(const QString& name, const QString& lastname, const QString& password) override;

    void setupUI() override;

private:
    QStringList sessionHistory;

    // ویجت‌های اختصاصی
    QPushButton* btn_viewHistory = nullptr;
    QListWidget* sessionHistoryListWidget = nullptr;

private slots:
    void showSessionHistory();
};

#endif // REGULARUSER_H
