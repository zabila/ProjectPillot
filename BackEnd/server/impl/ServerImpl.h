#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "BackEnd/server/impl/TcpServer.h"
#include "Common/network/Enums.h"
#include "Common/network/Types.h"

namespace server {
class ServerImpl {
 public:
  ServerImpl();

  void setHostAddress(const std::string &host, uint16_t port);
  bool connectionToHostAdress();
  bool sendToClientStdString(const std::string &text);
  bool sendToClientStdInt32(std::int32_t number);

 private:
  HostAddress mHostAddress;
  std::unique_ptr<TcpServer> mTcpServer;
};
}  // namespace server
