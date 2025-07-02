#include "sessionmanager.h"
#include <QRandomGenerator>

SessionManager& SessionManager::getInstance() {
    static SessionManager instance;
    return instance;
}

Session* SessionManager::createSession() {
    QString sessionId = QString::number(QRandomGenerator::global()->bounded(100000, 999999));
    Session* session = new Session(sessionId);
    sessions.insert(sessionId, session);
    return session;
}

Session* SessionManager::findSession(const QString& sessionId) {
    if (sessions.contains(sessionId) && sessions[sessionId]->isActive()) {
        return sessions[sessionId];
    }
    return nullptr;
}
