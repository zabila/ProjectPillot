#pragma once

// STD
#include <memory>

// Qt
#include <QObject>

namespace ctrl {
class ServerController;
}

class ServerSettingsUI : public QObject {
  Q_OBJECT
 public:
  explicit ServerSettingsUI(QObject* parent = nullptr);
  void setServerController(
      const std::shared_ptr<ctrl::ServerController>& serverCtrl);

 signals:
  void connectinStatus(bool status);

 public slots:
  void receivedHostAndPort(QString host, quint16 port);

 private:
  std::shared_ptr<ctrl::ServerController> mpServerController;
};
