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
  ~TcpServer();

  void setConnectAdress(const Adress& adress);
  bool StartServer();

 public slots:
  void newConnection();
  void readyRead();

 private:
  QTcpServer* mpQtcpServer;
  QTcpSocket* mpQtcpSocket;
  Adress mAdress;
};
}  // namespace network
