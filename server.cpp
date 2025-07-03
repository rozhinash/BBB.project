#include "server.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent) {}

void Server::startServer(quint16 port) {
    if (listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port" << port;
    } else {
        qDebug() << "Failed to start server:" << errorString();
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    auto* socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::onDisconnected);

    qDebug() << "New connection from" << socket->peerAddress().toString();
}

void Server::onReadyRead() {
    auto* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    QByteArray data = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return;

    QJsonObject message = doc.object();
    processMessage(socket, message);
}

void Server::onDisconnected() {
    auto* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    clientSessions.remove(socket);
    socket->deleteLater();
}

void Server::processMessage(QTcpSocket* client, const QJsonObject& message) {
    QString type = message["type"].toString();

    if (type == "create_session") {
        Session* session = SessionManager::getInstance().createSession();
        QString sessionId = session->getSessionId();

        clientSessions[client] = sessionId;

        QJsonObject response;
        response["type"] = "session_created";
        response["sessionId"] = sessionId;
        client->write(QJsonDocument(response).toJson());

    } else if (type == "join_session") {
        QString sessionId = message["sessionId"].toString();
        Session* session = SessionManager::getInstance().findSession(sessionId);

        QJsonObject response;
        if (session && session->isActive()) {
            clientSessions[client] = sessionId;
            response["type"] = "session_joined";
            response["sessionId"] = sessionId;
        } else {
            response["type"] = "error";
            response["message"] = "Invalid or inactive session";
        }
        client->write(QJsonDocument(response).toJson());
    }

    // سایر پیام‌ها مثل leave_session، end_session، draw_change، و غیره بعدا اضافه می‌شن
}