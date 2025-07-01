#ifndef SESSION_H
#define SESSION_H
#include <QString>
//#include <QDataTime>
class Session
{
public:
    Session(QString sessionId);
    QString getSessionId() const;

private:
    QString sessionId;
};

#endif// SESSION_H
