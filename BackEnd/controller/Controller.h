#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

namespace server {
class Server;
}
namespace ui {
class View;
}

namespace ctrl {
class ControllerImpl;
class Controller {
 public:
  explicit Controller();

  void init(std::shared_ptr<server::Server> server,
            std::shared_ptr<ui::View> view);

  void addListeningPort(std::uint16_t port);

 private:
  std::shared_ptr<ControllerImpl> mImpl;
};
}  // namespace ctrl

#endif  // CONTROLLER_H
