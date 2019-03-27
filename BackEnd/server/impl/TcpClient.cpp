#include <utility>

#include "TcpClient.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "Common/network/Types.h"

namespace network {
    TcpClient::TcpClient(QTcpSocket *socket, std::string mNameClient) :
            qTcpSocket(socket),
            mNameClient(std::move(mNameClient)),
            id(ClientId++) {
        LOG_TRACE("Create TcpClient with id " << id);
    }

    bool TcpClient::isValid() const {
        REQUIRE_R(qTcpSocket, "qTcpSocket invalid.", false);
        return qTcpSocket->isValid();
    }

    QTcpSocket *TcpClient::getQTcpSocket() const {
        REQUIRE_R(qTcpSocket, "qTcpSocket invalid.", nullptr);
        return qTcpSocket;
    }

    const std::uint32_t TcpClient::getId() const {
        return id;
    }
}