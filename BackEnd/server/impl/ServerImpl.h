#pragma once

#include <cstdint>
#include <string>

#include <boost/asio.hpp>

#include "Common/network/Enums.h"
#include "Common/network/Types.h"

namespace server {
class ServerImpl {
  public:
    void setHostAddress(const std::string &host, uint16_t port);
    HostAddress getHostAddress() const;
    bool connectionToHostAdress();
    bool sendToClientStdString(const std::string &text);
    bool sendToClientStdInt32(std::int32_t number);

  private:
    boost::asio::io_service mService;
    boost::asio::ip::tcp::acceptor mAcceptor;
    HostAddress mHostAddress;
};
} // namespace server
