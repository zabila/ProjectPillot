#include "TcpServer.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "Common/server/Enums.h"

namespace server {

TcpServer::TcpServer(uint16_t port, QObject *parent) : QObject(parent) {
  LOG_TRACE("")
  qTcpServer = new QTcpServer();
  connect(qTcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));

  listeningPort(port);
}

TcpServer::~TcpServer() {
  LOG_TRACE("");
  delete qTcpServer;
}

void TcpServer::listeningPort(std::uint16_t port) {
  REQUIRE(qTcpServer, "qTcpServer invalid.");
  REQUIRE(port, "port invalid.")
  LOG_INFO("Port: " << port);
  bool result = qTcpServer->listen(QHostAddress::Any, port);
  LOG_INFO("Connect result: " << std::boolalpha << result);
}

void TcpServer::newConnection() {
  LOG_TRACE("");
  REQUIRE(qTcpServer, "qTcpServer invalid.")

  qTcpSocket = qTcpServer->nextPendingConnection();
  qTcpSocket->write("Client connected to ProjectPilot.\r\n");

  if (!qTcpSocket) {
    LOG_ERROR("qTcpSocket invalid.");
    return;
  }
  connect(qTcpSocket, &QTcpSocket::readyRead, this, &TcpServer::readyRead);
}

void TcpServer::readyRead() {
  LOG_TRACE("");
  while (qTcpSocket->bytesAvailable() > 0) {
    QByteArray array = qTcpSocket->readAll();

    // TODO
    qTcpSocket->write(array);
  }
}
}  // namespace server
