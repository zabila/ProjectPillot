#include "ServerImpl.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "TcpServer.h"

namespace server {

ServerImpl::ServerImpl(std::shared_ptr<ctrl::Controller> ctrl)
    : mpController(ctrl) {}

void ServerImpl::addListeningPort(uint16_t port, std::string name) {
  mListeners[name] = std::make_unique<TcpServer>(port);
}

}  // namespace server
