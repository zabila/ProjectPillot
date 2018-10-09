#include "Enums.h"

std::ostream &operator<<(std::ostream &os, network::ServerError sr) {
    switch (sr) {
    case network::ServerError::None:
        os << "ServerError::None";
        break;
    case network::ServerError::Error:
        os << "ServerError::Error";
        break;
    case network::ServerError::NotConnected:
        os << "ServerError::NotConnected";
        break;
    case network::ServerError::HostAddressNotValid:
        os << "ServerError::HostAddressNotValid";
        break;
    case network::ServerError::Invalid:
        os << "ServerError::Invalid";
        break;
    }
    return os;
}
