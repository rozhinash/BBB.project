#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "session.h"
#include <QMap>

class SessionManager
{
public:
    static SessionManager& getInstance();
    Session* createSession();
    Session* findSession(const QString& sessionId);

private:
    SessionManager() {}
    QMap<QString, Session*> sessions;
};

#endif // SESSIONMANAGER_H
