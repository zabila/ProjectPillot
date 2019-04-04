#include "ControllerImpl.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "server/Server.h"

namespace ctrl {
ControllerImpl::ControllerImpl(std::shared_ptr<server::Server> server,
                               std::shared_ptr<ui::View> view)
    : mpServer(server), mpView(view) {}

void ControllerImpl::addListeningPort(uint16_t port) {
  REQUIRE(mpServer, "mpServer invalid.");
  mpServer->addListeningPort(port);
}

}  // namespace ctrl
