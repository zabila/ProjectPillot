#pragma once

#include <memory>
#include <vector>

#include <QtNetwork>

#include "Common/server/Types.h"

namespace server {
class TcpServer : public QObject {
  Q_OBJECT
 public:
  explicit TcpServer(std::uint16_t port = INVALID_PORT,
                     QObject* parent = nullptr);
  ~TcpServer() override;

  void listeningPort(std::uint16_t port);

 public slots:
  void newConnection();
  void readyRead();

 private:
  QTcpServer* qTcpServer;
  QTcpSocket* qTcpSocket;
};
}  // namespace server
