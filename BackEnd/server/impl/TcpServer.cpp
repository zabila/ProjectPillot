#include "TcpServer.h"

#include <unistd.h>

#include "Common/logger/logger.h"
#include "Common/macro.h"

namespace network {

TcpServer::TcpServer(QObject *parent) : QObject(parent) {
  LOG_TRACE("");
  mpQtcpServer = new QTcpServer();

  connect(mpQtcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

TcpServer::~TcpServer() {
  LOG_TRACE("");
  delete mpQtcpServer;
  delete mpQtcpSocket;
}

void TcpServer::setConnectAdress(const Adress &adress) {
  LOG_TRACE("");
  LOG_INFO(adress)
  mAdress = adress;
}

bool TcpServer::StartServer() {
  LOG_TRACE("");
  REQUIRE_R(mAdress.is_valid(), "Adress invalid.", false);
  REQUIRE_R(mpQtcpServer, "mpQtcpServer invalid.", false);

  QHostAddress qHostAdress(mAdress.host.c_str());
  bool result = false;
  result =
      mpQtcpServer->listen(QHostAddress(mAdress.host.c_str()), mAdress.port);

  if (result) {
    LOG_INFO("Server started" << mAdress)
  } else {
    LOG_ERROR("Server not started.");
    return result;
  }

  return result;
}

void TcpServer::newConnection() {
  LOG_TRACE("");
  REQUIRE(mpQtcpServer, "mpQtcpServer invalid.")

  mpQtcpSocket = mpQtcpServer->nextPendingConnection();

  mpQtcpSocket->write("Client connected.\r\n");

  if (!mpQtcpSocket || !mpQtcpSocket->isValid()) {
    LOG_ERROR("mpQtcpSocket invalid.");
    return;
  }

  connect(mpQtcpSocket, &QTcpSocket::readyRead, this, &TcpServer::readyRead);
}

void TcpServer::readyRead() {
  LOG_TRACE("");
  while (mpQtcpSocket->bytesAvailable() > 0) {
    QByteArray array = mpQtcpSocket->readAll();

    mpQtcpSocket->write(array);
  }
}
}  // namespace network
