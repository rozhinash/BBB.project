#ifndef SESSION_H
#define SESSION_H

#include <QString>

class Session
{
public:
    Session(QString sessionId);
    QString getSessionId() const;
    bool isActive() const;
    void endSession();

private:
    QString sessionId;
    bool active;
};

#endif // SESSION_H
