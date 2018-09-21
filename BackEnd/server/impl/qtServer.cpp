#include "qtServer.h"

QtServer::QtServer(QObject *parent) : QObject(parent) {
  mQtcpServer = std::make_unique<QTcpServer>(this);
}

bool QtServer::connectionToHostAdress(const QString &host, uint16_t port) {
  connect(mQtcpServer.get(), SIGNAL(newConnection()), this,
          SLOT(newConnection()));
  return mQtcpServer->listen(QHostAddress(host), port);
}

void QtServer::newConnection() {
  QTcpSocket *socket = mQtcpServer->nextPendingConnection();

  socket->write("Hello client. \n");
  socket->flush();
  socket->waitForBytesWritten(3000);
}
