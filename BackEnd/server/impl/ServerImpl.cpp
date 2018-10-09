#include "ServerImpl.h"

namespace server {

bool ServerImpl::connectionToHostAdress() {}

bool ServerImpl::sendToClientStdString(const std::string &text) {
    if (text.empty())
        return false;
    return true;
}

bool ServerImpl::sendToClientStdInt32(int32_t number) { return true; }

void ServerImpl::setHostAddress(const std::string &host, uint16_t port) {
    mHostAddress.host = host;
    mHostAddress.port = port;
}

HostAddress ServerImpl::getHostAddress() const { return mHostAddress; }

} // namespace server
