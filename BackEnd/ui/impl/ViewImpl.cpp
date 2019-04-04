#include "ViewImpl.h"

#include "Common/logger/logger.h"

namespace ui {

ViewImpl::ViewImpl(std::shared_ptr<ctrl::Controller> ctrl)
    : window(this), mpController(ctrl) {
  window.show();
}

void ViewImpl::onAddListing(uint16_t port, std::string) {
  mpController->addListeningPort(port);
}
}  // namespace ui
