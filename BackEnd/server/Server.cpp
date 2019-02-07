#include "Server.h"

#include "impl/ServerImpl.h"

// Qt
#include <QtDebug>

namespace server {

void Server::init() {
  qDebug() << "Init Server";
  mImpl = std::make_shared<ServerImpl>();
  mImpl->setHostAddress("127.0.0.1", 9999);
  mImpl->connectionToHostAdress();
}

network::ServerError Server::setHostAddress(std::string &host, uint16_t port) {
  if (!mImpl) {
    return network::ServerError::Invalid;
  }
  mImpl->setHostAddress(std::move(host), std::move(port));
  return network::ServerError::None;
}

network::ServerError Server::connectionToHostAdress() {
  if (!mImpl) {
    return network::ServerError::Invalid;
  }

  bool result = mImpl->connectionToHostAdress();
  return result ? network::ServerError::None
                : network::ServerError::NotConnected;
}

network::ServerError Server::sendToClientStdString(const std::string &text) {
  if (!mImpl) {
    return network::ServerError::Invalid;
  }
  bool result = mImpl->sendToClientStdString(text);
  return result ? network::ServerError::None : network::ServerError::Error;
}

network::ServerError Server::sendToClientStdInt32(int32_t number) {
  if (!mImpl) {
    return network::ServerError::Invalid;
  }
  bool result = mImpl->sendToClientStdInt32(number);
  return result ? network::ServerError::None : network::ServerError::Error;
}

}  // namespace server
