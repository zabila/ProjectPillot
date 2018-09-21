#pragma once

#include <memory>
#include <string>

#include "common/server/serverEnums.h"

namespace server {

// forward
class ServerImpl;

class Server {
public:
  Server();
  ~Server();
  ServerError connectionToHostAdress(const std::string &host,
                                     std::uint16_t port);

private:
  std::unique_ptr<ServerImpl> mServerImpl;
};
} // namespace server
