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
  TcpServer(QObject* parent = nullptr);

  void setConnectAdress(Adress&& adress);

  bool start_server();

 public slots:
  void newConnection();

 private:
  std::unique_ptr<QTcpServer> mpQtcpServer;
  Adress mAdress;
};
}  // namespace network
