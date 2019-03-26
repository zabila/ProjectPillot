#include "Server.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "impl/ServerImpl.h"

// Qt
#include <QtDebug>

namespace server {

Server::Server() : mImpl(std::make_shared<ServerImpl>()) { LOG_TRACE(""); }

void Server::setControllers(
    const std::shared_ptr<ctrl::ServerController> &arg) {
  LOG_TRACE("");
  REQUIRE(mImpl, "mImpl invalid.")
  mImpl->setControllers(arg);
}

network::ServerError Server::setHostAddress(const network::Adress &address) {
  LOG_TRACE("");
  REQUIRE_R(mImpl, "mImpl invalid.", network::ServerError::Invalid);
  mImpl->setHostAddress(address);
  return network::ServerError::None;
}

network::ServerError Server::connectionToHostAddress() {
  LOG_TRACE("");
  REQUIRE_R(mImpl, "mImpl invalid.", network::ServerError::Invalid);

  bool result = mImpl->connectionToHostAdress();
  return result ? network::ServerError::None
                : network::ServerError::NotConnected;
}

network::ServerError Server::sendToClientStdString(const std::string &text) {
  LOG_TRACE("");
  REQUIRE_R(mImpl, "mImpl invalid.", network::ServerError::Invalid);

  bool result = mImpl->sendToClientStdString(text);
  return result ? network::ServerError::None : network::ServerError::Error;
}

network::ServerError Server::sendToClientStdInt32(int32_t number) {
  LOG_TRACE("");
  REQUIRE_R(mImpl, "mImpl invalid.", network::ServerError::Invalid);

  bool result = mImpl->sendToClientStdInt32(number);
  return result ? network::ServerError::None : network::ServerError::Error;
}

}  // namespace server
