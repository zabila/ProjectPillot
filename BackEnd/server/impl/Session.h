#pragma once

#include <boost/asio.hpp>

namespace server {
class Session {
  public:
  private:
    boost::asio::ip::tcp::socket mSocket;
};
} // namespace server
