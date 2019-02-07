#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "Common/network/Enums.h"
#include "Common/network/Types.h"
#include "TcpServer.h"

namespace server {
class ServerImpl {
 public:
  ServerImpl();

  void setHostAddress(std::string &&host, uint16_t &&port);
  bool connectionToHostAdress();
  bool sendToClientStdString(const std::string &text);
  bool sendToClientStdInt32(std::int32_t number);

 private:
  std::unique_ptr<network::TcpServer> mTcpServer;
};
}  // namespace server
