#include "admin.h"
#include "session.h"  //وقتی کلاس جلسه رو ساختی اینو بساز
User::User(QString name ,QString lastname ,QString password , Role level)
    :userLevel(level) , name(name),lastname(lastname),password(password){
    setupUI();
}


Role Admin::getRole()const{
    return adminLevel;
}


bool Admin::createSession(const Session& session){
    return adminLevel == Role::Admin || adminLevel == Role::SuperAdmin;
}

bool Admin::deleteSession(int sessionId){
    return adminLevel == Role::Admin || adminLevel == Role::SuperAdmin;
}

bool Admin::manageUser(User& /*user*/ , const QString& /*action*/){
    return adminLevel == Role::SuperAdmin;
}
