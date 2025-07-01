#ifndef ADMIN_H
#define ADMIN_H
#include  "../User/user.h"
#include "role.h"
class Session ;//forward declaration

    class Admin : public User{
 private:
        Role adminLevel;
public:


    Admin(  QString name  , QString lastname  ,const QString &password , Role level);
    Role getRole() const;

    bool createSession(const Session& session);
    bool deleteSession(int sessionId);
    bool manageUser(User& user , const QString& action);

};


#endif// ADMIN_H
