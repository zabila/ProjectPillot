#pragma once

// STD
#include <memory>

// Qt
#include <QQmlApplicationEngine>

// Ui
#include "ui/impl/ServerSettingsUI.h"

namespace ctrl {
class ServerController;
}

namespace ui {
class ViewModel {
 public:
  ViewModel();
  void setControllers(const std::shared_ptr<ctrl::ServerController>& server);

  void sendServerStatus(bool);

 private:
  void registration_all_qml();

 private:
  QQmlApplicationEngine engine;

  // QML
  ServerSettingsUI mServerSettingsUI;
};
}  // namespace ui
