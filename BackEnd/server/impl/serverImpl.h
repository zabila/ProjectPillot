#pragma once

#include "impl/qtServer.h"

namespace server {
class ServerImpl {
public:
  bool connectionToHostAdress(const std::string &host, uint16_t port);

private:
  QtServer mQtServer;
};
} // namespace server
