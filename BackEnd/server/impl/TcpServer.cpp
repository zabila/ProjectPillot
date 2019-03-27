#include "TcpServer.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"

namespace network {

    TcpServer::TcpServer(QObject *parent) : QObject(parent) {
        LOG_TRACE("");
        qTcpServer = new QTcpServer();

        connect(qTcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    }

    TcpServer::~TcpServer() {
        LOG_TRACE("");
        delete qTcpServer;
    }

    void TcpServer::setConnectAddress(const Address &address) {
        LOG_INFO(address)
        mAddress = address;
    }

    bool TcpServer::StartServer() {
        LOG_TRACE("");
        REQUIRE_R(mAddress.is_valid(), "Address invalid.", false);
        REQUIRE_R(qTcpServer, "qTcpServer invalid.", false);

        bool result = false;
        result = qTcpServer->listen(QHostAddress::Any, mAddress.port);

        if (result) {
            LOG_INFO("Server started" << mAddress)
        } else {
            LOG_ERROR("Server not started.");
            return result;
        }

        return result;
    }

    void TcpServer::newConnection() {
        LOG_TRACE("");
        REQUIRE(qTcpServer, "qTcpServer invalid.")

        QTcpSocket *socket = qTcpServer->nextPendingConnection();
        socket->write("Client connected to Server ProjectPilot.\r\n");

        mClients.emplace_back(TcpClient(socket, "Vova Zabila"));

        if (!mClients.back().isValid()) {
            LOG_ERROR("qTcpSocket invalid.");
            return;
        }

        connect(mClients.back().getQTcpSocket(), &QTcpSocket::readyRead, this, &TcpServer::readyRead);
    }

    void TcpServer::readyRead() {
        LOG_TRACE("mClients with id " << mClients.back().getId() );
        while (mClients.back().getQTcpSocket()->bytesAvailable() > 0) {
            QByteArray array = mClients.back().getQTcpSocket()->readAll();

            mClients.back().getQTcpSocket()->write(array);
        }
    }
}  // namespace network
