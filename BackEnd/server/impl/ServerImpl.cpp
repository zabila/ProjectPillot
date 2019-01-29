#include "ServerImpl.h"

#include "TcpServer.h"

namespace server {

ServerImpl::ServerImpl() {
  mTcpServer = std::make_unique<TcpServer>();
  qDebug() << "Construct ServerImpl";
}

bool ServerImpl::connectionToHostAdress() {
  if (!mTcpServer) {
    qDebug() << "mTcpServer ivalid.";
    return false;
  }
  mTcpServer->start_server(mHostAddress.host, mHostAddress.port);
  return true;
}

bool ServerImpl::sendToClientStdString(const std::string &text) {
  if (text.empty()) return false;
  return true;
}

bool ServerImpl::sendToClientStdInt32(int32_t) { return true; }

void ServerImpl::setHostAddress(const std::string &host, uint16_t port) {
  mHostAddress = {host, port};
}

}  // namespace server
