#pragma once

#include <iostream>

namespace network {
enum ServerError {
    None = 0,
    Invalid,
    Error,
    NotConnected,
    HostAddressNotValid,
};

enum MessageType {
    StdString = 0,
    StdInt32,
};
} // namespace network

std::ostream &operator<<(std::ostream &os, network::ServerError sr);
