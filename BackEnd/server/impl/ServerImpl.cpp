#include "ServerImpl.h"

#include "TcpServer.h"

namespace server {

ServerImpl::ServerImpl() {
  mTcpServer = std::make_unique<network::TcpServer>();
  qDebug() << "Construct ServerImpl";
}

bool ServerImpl::connectionToHostAdress() {
  if (!mTcpServer) {
    qDebug() << "mTcpServer ivalid.";
    return false;
  }
  return mTcpServer->start_server();
}

bool ServerImpl::sendToClientStdString(const std::string &text) {
  if (text.empty()) return false;
  return true;
}

bool ServerImpl::sendToClientStdInt32(int32_t) { return true; }

void ServerImpl::setHostAddress(std::string &&host, uint16_t &&port) {
  if (!mTcpServer) {
    qDebug() << "mTcpServer ivalid.";
    return;
  }
  mTcpServer->setConnectAdress({std::move(host), std::move(port)});
}

}  // namespace server
