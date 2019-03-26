#include "TcpServer.h"

#include <unistd.h>

#include "Common/logger/logger.h"
#include "Common/macro.h"

namespace network {

TcpServer::TcpServer(QObject *parent) : QObject(parent) {
  LOG_TRACE("");
  qTcpServer = new QTcpServer();

  connect(qTcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

TcpServer::~TcpServer() {
  LOG_TRACE("");
  delete qTcpServer;
  delete qTcpSocket;
}

void TcpServer::setConnectAddress(const Adress &address) {
  LOG_TRACE("");
  LOG_INFO(address)
  mAddress = address;
}

bool TcpServer::StartServer() {
  LOG_TRACE("");
  REQUIRE_R(mAddress.is_valid(), "Address invalid.", false);
  REQUIRE_R(qTcpServer, "qTcpServer invalid.", false);

  bool result = false;
  result = qTcpServer->listen(QHostAddress(mAddress.host.c_str()), mAddress.port);

  if (result) {
    LOG_INFO("Server started" << mAddress)
  } else {
    LOG_ERROR("Server not started.");
    return result;
  }

  return result;
}

void TcpServer::newConnection() {
  LOG_TRACE("");
  REQUIRE(qTcpServer, "qTcpServer invalid.")

  qTcpSocket = qTcpServer->nextPendingConnection();

  qTcpSocket->write("Client connected.\r\n");

  if (!qTcpSocket || !qTcpSocket->isValid()) {
    LOG_ERROR("qTcpSocket invalid.");
    return;
  }

  connect(qTcpSocket, &QTcpSocket::readyRead, this, &TcpServer::readyRead);
}

void TcpServer::readyRead() {
  LOG_TRACE("");
  while (qTcpSocket->bytesAvailable() > 0) {
    QByteArray array = qTcpSocket->readAll();

    qTcpSocket->write(array);
  }
}
}  // namespace network
