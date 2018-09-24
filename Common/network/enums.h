#pragma once

#include <iostream>

namespace server {
enum ServerError {
    None = 0,
    Error,
    NotConnected,
    HostAddressNotValid,
};

enum SendType {
    MessagesStdString = 0,
    MessagesStdInt32,
};
} // namespace server

std::ostream &operator<<(std::ostream &os, server::ServerError sr);
