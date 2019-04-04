#include "View.h"

#include "Common/logger/logger.h"
#include "controller/Controller.h"
#include "ui/impl/ViewImpl.h"

namespace ui {

View::View() : mImpl(nullptr) {}

void View::init(std::shared_ptr<ctrl::Controller> ctrl) {
  LOG_TRACE("")
  mImpl = std::make_shared<ViewImpl>(ctrl);
}

void View::setStatusConnect(bool status) { LOG_INFO(status) }

}  // namespace ui
