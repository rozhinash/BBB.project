#include "session.h"

Session::Session(QString sessionId) : sessionId(sessionId) {}

QString Session::getSessionId() const{
   return sessionId;
}
