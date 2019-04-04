#include "Server.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "controller/Controller.h"
#include "impl/ServerImpl.h"

namespace server {
Server::Server() : mImpl(nullptr) {}

void Server::init(std::shared_ptr<ctrl::Controller> ctrl) {
  LOG_TRACE("")
  mImpl = std::make_shared<ServerImpl>(ctrl);
}

void Server::addListeningPort(uint16_t port) {
  REQUIRE(mImpl, "mImpl invalid.")
  mImpl->addListeningPort(port);
}
}  // namespace server
