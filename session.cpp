#include "session.h"

Session::Session(QString sessionId) : sessionId(sessionId), active(true) {}

QString Session::getSessionId() const {
    return sessionId;
}

bool Session::isActive() const {
    return active;
}

void Session::endSession() {
    active = false;
}
