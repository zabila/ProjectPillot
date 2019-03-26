#pragma once

// STD
#include <memory>

// Qt
#include <QtNetwork>

// Common
#include "Common/network/Types.h"

namespace network {
class TcpServer : public QObject {
  Q_OBJECT
 public:
  explicit TcpServer(QObject* parent = nullptr);
  ~TcpServer() override;

  void setConnectAddress(const Adress &address);
  bool StartServer();

 public slots:
  void newConnection();
  void readyRead();

 private:
  QTcpServer* qTcpServer;
  QTcpSocket* qTcpSocket;
  Adress mAddress;
};
}  // namespace network
