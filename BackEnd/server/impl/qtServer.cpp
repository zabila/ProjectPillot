#include "qtServer.h"

#include <QDataStream>

QtServer::QtServer(QObject *parent) : QObject(parent) {
    mQtcpServer = std::make_unique<QTcpServer>(this);
}

bool QtServer::connectionToHostAdress(const QString &host, uint16_t port) {

    bool result = mQtcpServer->listen(QHostAddress(host), port);
    connect(mQtcpServer.get(), &QTcpServer::newConnection, this, &QtServer::onNewConnect);
    return result;
}

void QtServer::onNewConnect() {
    QTcpSocket *socket = mQtcpServer->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    socket->write("Connect is server.");
}

void QtServer::disconnected() { qDebug() << "disconnected"; }

void QtServer::readyRead() {
    QTcpSocket *socket = static_cast<QTcpSocket *>(sender());
    QByteArray data = socket->readAll();
    qDebug("%s", data.constData());
}

void QtServer::SendSerializedDataToClient(const QByteArray &data) {
    if (data.isEmpty())
        return;

    QTcpSocket *socket = mQtcpServer->nextPendingConnection();
    if (socket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Is connect.";
        socket->write(data);
    }
}
