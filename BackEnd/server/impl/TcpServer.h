#pragma once

// STD
#include <memory>

// Qt
#include <QtNetwork>

class TcpServer : public QObject {
  Q_OBJECT
 public:
  TcpServer(QObject *parent = nullptr);

  void start_server(const std::string &host, uint16_t port);

 public slots:
  void newConnection();

 private:
  std::unique_ptr<QTcpServer> mpQtcpServer;
};
