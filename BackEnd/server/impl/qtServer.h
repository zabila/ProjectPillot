#pragma once

#include <cstdint>
#include <memory>

#include <QDebug>
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

class QtServer : public QObject {
  Q_OBJECT
public:
  explicit QtServer(QObject *parent = nullptr);

  bool connectionToHostAdress(const QString &host, uint16_t port);

public slots:
  void newConnection();

private:
  std::unique_ptr<QTcpServer> mQtcpServer;
};
