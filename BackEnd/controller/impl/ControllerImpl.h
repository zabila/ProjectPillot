#ifndef CONTROLLERIMPL_H
#define CONTROLLERIMPL_H

#include <memory>

#include "server/Server.h"
#include "ui/View.h"

namespace ctrl {
class ControllerImpl {
 public:
  ControllerImpl(std::shared_ptr<server::Server> server,
                 std::shared_ptr<ui::View> view);

  void addListeningPort(std::uint16_t port);

 private:
  std::shared_ptr<server::Server> mpServer;
  std::shared_ptr<ui::View> mpView;
};
}  // namespace ctrl

#endif  // CONTROLLERIMPL_H
