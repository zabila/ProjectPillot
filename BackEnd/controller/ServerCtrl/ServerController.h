#pragma once

#include <memory>

#include "Common/network/Types.h"

namespace server {
class Server;
}
namespace ui {
class ViewModel;
}

namespace ctrl {
class ServerController {
 public:
  void init(const std::shared_ptr<server::Server>& server,
            const std::shared_ptr<ui::ViewModel>& ui);

  void connectToServer(const network::Address& adress);
  void onConnectToServer(bool status);

 private:
  std::shared_ptr<server::Server> mpServer;
  std::shared_ptr<ui::ViewModel> mpViewer;
};
}  // namespace ctrl
