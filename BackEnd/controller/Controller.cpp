#include "Controller.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "controller/impl/ControllerImpl.h"

namespace ctrl {

Controller::Controller() : mImpl(nullptr) {}

void Controller::init(std::shared_ptr<server::Server> server,
                      std::shared_ptr<ui::View> view) {
  LOG_TRACE("")
  mImpl = std::make_shared<ControllerImpl>(server, view);
}

void Controller::addListeningPort(uint16_t port) {
  REQUIRE(mImpl, "mImpl invalid.");
  mImpl->addListeningPort(port);
}

}  // namespace ctrl
