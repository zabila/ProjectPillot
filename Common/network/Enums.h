#pragma once

#include <iostream>

namespace network {
    enum class ServerError : int {
        None = 0,
        Invalid,
        Error,
        NotConnected,
        HostAddressNotValid,
    };

    enum class MessageType : int {
        ClientId = 0,
        StdInt32,
    };
}  // namespace network

std::ostream &operator<<(std::ostream &os, network::ServerError sr);
