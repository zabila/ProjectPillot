#pragma once

// STD
#include <memory>
#include <vector>

// Qt
#include <QtNetwork>

// Common
#include "Common/network/Types.h"

#include "TcpClient.h"

namespace network {
class TcpServer : public QObject {
  Q_OBJECT
 public:
  explicit TcpServer(QObject* parent = nullptr);
  ~TcpServer() override;

  void setConnectAddress(const Address &address);
  bool StartServer();

 public slots:
  void newConnection();
  void readyRead();

 private:
  QTcpServer* qTcpServer;

  Clients mClients;
  Address mAddress;
};
}  // namespace network
