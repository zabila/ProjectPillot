#pragma once

#include <cstdint>
#include <memory>

#include <QByteArray>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

#include "Common/network/enums.h"

class QtServer : public QObject {
    Q_OBJECT
  public:
    explicit QtServer(QObject *parent = nullptr);

    void setHostAddressAndPort(const QString &host, uint16_t port);
    bool connectionToHostAdress(const QString &host, uint16_t port);

  public slots:
    void onNewConnect();
    void disconnected();
    void readyRead();
    void SendSerializedDataToClient(const QByteArray &data);

  private:
    std::unique_ptr<QTcpServer> mQtcpServer;
};
