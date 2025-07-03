#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include "sessionmanager.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void startServer(quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    QMap<QTcpSocket*, QString> clientSessions; // Maps socket to sessionId
    void processMessage(QTcpSocket* client, const QJsonObject& message);
};

#endif // SERVER_H