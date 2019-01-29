#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "Common/network/Enums.h"

namespace server {

// forward
class ServerImpl;

class Server {
 public:
  void init();

  network::ServerError setHostAddress(const std::string &host, uint16_t port);
  network::ServerError connectionToHostAdress();
  network::ServerError sendToClientStdString(const std::string &text);
  network::ServerError sendToClientStdInt32(std::int32_t number);

 private:
  std::shared_ptr<ServerImpl> mImpl;
};
}  // namespace server
