#include "TcpServer.h"

#include <QtDebug>

#include <unistd.h>

namespace network {

TcpServer::TcpServer(QObject *parent) : QObject(parent) {
  mpQtcpServer = std::make_unique<QTcpServer>();

  connect(mpQtcpServer.get(), SIGNAL(newConnection()), this,
          SLOT(newConnection()));

  qDebug() << "Constructor TcpServer";
}

void TcpServer::setConnectAdress(Adress &&adress) {
  mAdress = std::move(adress);
}

bool TcpServer::start_server() {
  bool result = false;
  if (!mAdress.is_valid()) {
    qDebug() << "Adress invalid.";
    return result;
  }
  QHostAddress qHostAdress(std::move(mAdress.host.c_str()));
  qDebug() << "Start server with host:" << qHostAdress
           << " port:" << mAdress.port;

  if (!mpQtcpServer) {
    qDebug() << "mpQtcpServer invalid.";
    return result;
  }

  result =
      mpQtcpServer->listen(QHostAddress(mAdress.host.c_str()), mAdress.port);

  if (result) {
    qDebug() << "Server started.";
  } else {
    qDebug() << "Server not started.";
  }
  return result;
}

void TcpServer::newConnection() {
  if (!mpQtcpServer) {
    qDebug() << "mpQtcpServer invalid.";
    return;
  }

  sleep(10000);

  QTcpSocket *socket = mpQtcpServer->nextPendingConnection();

  socket->write("Hello client\r\n");
  socket->flush();

  socket->waitForBytesWritten(3000);

  socket->close();
}
}  // namespace network
