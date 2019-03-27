#pragma once

#include <QTcpSocket>

#include <string>

static std::uint32_t id;

namespace network {
    class TcpClient {
    public:
        explicit TcpClient(QTcpSocket *socket, std::string mNameClient);

        bool isValid() const;

        const std::uint32_t getId() const;

        QTcpSocket *getQTcpSocket() const;

    private:
        std::uint32_t id;
        std::string mNameClient;
        QTcpSocket *qTcpSocket;
    };

    using Clients = std::vector<TcpClient>;
}