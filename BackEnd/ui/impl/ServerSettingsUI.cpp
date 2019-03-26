#include "ServerSettingsUI.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "controller/ServerCtrl/ServerController.h"

ServerSettingsUI::ServerSettingsUI(QObject *parent) : QObject(parent) {}

void ServerSettingsUI::setServerController(
    const std::shared_ptr<ctrl::ServerController> &serverCtrl) {
  mpServerController = serverCtrl;
}

void ServerSettingsUI::receivedHostAndPort(QString host, quint16 port) {
  network::Adress adress{host.toStdString(), port};
  LOG_INFO("Resived host from qml: " << adress);
  REQUIRE(mpServerController, "Server controller invalid.")
  mpServerController->connectToServer(adress);
}
