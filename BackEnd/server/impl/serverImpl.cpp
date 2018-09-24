#include "serverImpl.h"

#include <QByteArray>
#include <QString>

#include "Common/network/serDesHelper.h"

namespace server {

bool ServerImpl::connectionToHostAdress() {
    QString qhost = QString::fromStdString(mHostAddress.host);
    return mQtServer.connectionToHostAdress(qhost, mHostAddress.port);
}

bool ServerImpl::sendToClientStdString(const std::string &text) {
    if (text.empty())
        return false;
    QByteArray data;
    serialization::stdString(text, data);
    mQtServer.SendSerializedDataToClient(data);
    return true;
}

bool ServerImpl::sendToClientStdInt32(int32_t number) {
    QByteArray data;
    serialization::stdInt32(number, data);
    mQtServer.SendSerializedDataToClient(data);
    return true;
}

void ServerImpl::setHostAddress(const std::string &host, uint16_t port) {
    mHostAddress.host = host;
    mHostAddress.port = port;
}

HostAddress ServerImpl::getHostAddress() const { return mHostAddress; }

} // namespace server
