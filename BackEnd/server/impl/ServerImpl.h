#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "Common/network/Enums.h"
#include "Common/network/Types.h"
#include "TcpServer.h"

namespace ctrl {
class ServerController;
}

namespace server {
class ServerImpl {
 public:
  ServerImpl();

  void setControllers(const std::shared_ptr<ctrl::ServerController> &);

  void setHostAddress(const network::Adress &adress);
  bool connectionToHostAdress();
  bool sendToClientStdString(const std::string &text);
  bool sendToClientStdInt32(std::int32_t number);

 private:
  std::unique_ptr<network::TcpServer> mTcpServer;
  std::shared_ptr<ctrl::ServerController> mpServerController;
};
}  // namespace server
