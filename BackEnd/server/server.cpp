#include "server.h"

#include "impl/serverImpl.h"

namespace server {
Server::Server() { mServerImpl.reset(new ServerImpl); }

Server::~Server() {}

ServerError Server::setHostAddress(const std::string &host, uint16_t port) {
    if (!mServerImpl) {
        qDebug() << "mServerImpl is invalid.";
        return ServerError::Error;
    }
    mServerImpl->setHostAddress(host, port);
    return ServerError::None;
}

ServerError Server::connectionToHostAdress() {
    if (!mServerImpl) {
        qDebug() << "mServerImpl is invalid.";
        return ServerError::Error;
    }

    if (mServerImpl->getHostAddress().isValid()) {
        qDebug() << "Connect result: " << ServerError::HostAddressNotValid;
        return ServerError::HostAddressNotValid;
    }
    bool result = mServerImpl->connectionToHostAdress();
    qDebug() << "Connect result: " << result;
    return result ? ServerError::None : ServerError::NotConnected;
}

ServerError Server::connectionToHostAdress(const std::string &host, uint16_t port) {
    if (!mServerImpl) {
        qDebug() << "mServerImpl is invalid.";
        return ServerError::Error;
    }
    mServerImpl->setHostAddress(host, port);
    bool result = mServerImpl->connectionToHostAdress();
    qDebug() << "Connect result: " << result;
    return result ? ServerError::None : ServerError::NotConnected;
}

ServerError Server::sendToClientStdString(const std::string &text) {
    if (!mServerImpl) {
        qDebug() << "mServerImpl is invalid.";
        return ServerError::Error;
    }
    bool result = mServerImpl->sendToClientStdString(text);
    qDebug() << "Send result: " << result;
    return result ? ServerError::None : ServerError::Error;
}

ServerError Server::sendToClientStdInt32(int32_t number) {
    if (!mServerImpl) {
        qDebug() << "mServerImpl is invalid.";
        return ServerError::Error;
    }
    bool result = mServerImpl->sendToClientStdInt32(number);
    qDebug() << "Send result: " << result;
    return result ? ServerError::None : ServerError::Error;
}

} // namespace server
