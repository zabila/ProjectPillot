#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "Common/network/Enums.h"
#include "Common/network/Types.h"

namespace ctrl {
class ServerController;
}

namespace server {

// forward
class ServerImpl;

class Server {
 public:
  Server();

  void setControllers(const std::shared_ptr<ctrl::ServerController> &);

  network::ServerError setHostAddress(const network::Address &address);
  network::ServerError connectionToHostAddress();
  network::ServerError sendToClientStdString(const std::string &text);
  network::ServerError sendToClientStdInt32(std::int32_t number);

 private:
  std::shared_ptr<ServerImpl> mImpl;
};
}  // namespace server
