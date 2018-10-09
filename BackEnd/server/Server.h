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
    Server();
    ~Server();

    ServerError setHostAddress(const std::string &host, uint16_t port);
    ServerError connectionToHostAdress();
    ServerError connectionToHostAdress(const std::string &host, std::uint16_t port);
    ServerError sendToClientStdString(const std::string &text);
    ServerError sendToClientStdInt32(std::int32_t number);

  private:
    std::unique_ptr<ServerImpl> mServerImpl;
};
} // namespace server
