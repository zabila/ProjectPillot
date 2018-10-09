#include "Server.h"

#include "impl/ServerImpl.h"

namespace server {
Server::Server() {}

Server::~Server() {}

ServerError Server::setHostAddress(const std::string &host, uint16_t port) {
    if (!mServerImpl) {
        return ServerError::Error;
    }
    mServerImpl->setHostAddress(host, port);
    return ServerError::None;
}

ServerError Server::connectionToHostAdress() {
    if (!mServerImpl) {
        return ServerError::Error;
    }

    if (mServerImpl->getHostAddress().isValid()) {
        return ServerError::HostAddressNotValid;
    }
    bool result = mServerImpl->connectionToHostAdress();
    return result ? ServerError::None : ServerError::NotConnected;
}

ServerError Server::connectionToHostAdress(const std::string &host, uint16_t port) {
    if (!mServerImpl) {
        return ServerError::Error;
    }
    mServerImpl->setHostAddress(host, port);
    bool result = mServerImpl->connectionToHostAdress();
    return result ? ServerError::None : ServerError::NotConnected;
}

ServerError Server::sendToClientStdString(const std::string &text) {
    if (!mServerImpl) {
        return ServerError::Error;
    }
    bool result = mServerImpl->sendToClientStdString(text);
    return result ? ServerError::None : ServerError::Error;
}

ServerError Server::sendToClientStdInt32(int32_t number) {
    if (!mServerImpl) {
        return ServerError::Error;
    }
    bool result = mServerImpl->sendToClientStdInt32(number);
    return result ? ServerError::None : ServerError::Error;
}

} // namespace server
