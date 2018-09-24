#pragma once

#include <cstdint>
#include <string>

#include "Common/network/enums.h"
#include "Common/network/type.h"
#include "impl/qtServer.h"
;
namespace server {
class ServerImpl {
  public:
    void setHostAddress(const std::string &host, uint16_t port);
    HostAddress getHostAddress() const;
    bool connectionToHostAdress();
    bool sendToClientStdString(const std::string &text);
    bool sendToClientStdInt32(std::int32_t number);

  private:
    QtServer mQtServer;
    HostAddress mHostAddress;
};
} // namespace server
