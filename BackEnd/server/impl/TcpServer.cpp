#include "TcpServer.h"

#include <QtDebug>

TcpServer::TcpServer(QObject *parent) : QObject(parent) {
  mpQtcpServer = std::make_unique<QTcpServer>();

  connect(mpQtcpServer.get(), SIGNAL(newConnection()), this,
          SLOT(newConnection()));

  qDebug() << "Constructor TcpServer";
}

void TcpServer::start_server(const std::string &host, uint16_t port) {
  QHostAddress address(host.c_str());
  qDebug() << "Start server with host:" << address << " port:" << port;

  if (!mpQtcpServer) {
    qDebug() << "mpQtcpServer invalid.";
    return;
  }

  if (!mpQtcpServer->listen(address, port)) {
    qDebug() << "Server could not start";
  } else {
    qDebug() << "Server started!";
  }
}

void TcpServer::newConnection() {
  if (!mpQtcpServer) {
    qDebug() << "mpQtcpServer invalid.";
    return;
  }
  QTcpSocket *socket = mpQtcpServer->nextPendingConnection();

  socket->write("Hello client\r\n");
  socket->flush();

  socket->waitForBytesWritten(3000);

  socket->close();
}
