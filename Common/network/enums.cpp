#include "enums.h"

std::ostream &operator<<(std::ostream &os, server::ServerError sr) {
    switch (sr) {
    case server::ServerError::None:
        os << "ServerError::None";
        break;
    case server::ServerError::Error:
        os << "ServerError::Error";
        break;
    case server::ServerError::NotConnected:
        os << "ServerError::NotConnected";
        break;
    case server::ServerError::HostAddressNotValid:
        os << "ServerError::HostAddressNotValid";
        break;
    }
    return os;
}
