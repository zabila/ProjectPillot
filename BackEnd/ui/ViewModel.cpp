#include "ViewModel.h"

#include <QQmlContext>

#include "Common/logger/logger.h"

namespace ui {

ViewModel::ViewModel() {}

void ViewModel::setControllers(
    const std::shared_ptr<ctrl::ServerController>& serverCtrl) {
  LOG_TRACE("");
  mServerSettingsUI.setServerController(serverCtrl);

  registration_all_qml();
}

void ViewModel::sendServerStatus(bool status) {
  LOG_TRACE(status);
  mServerSettingsUI.connectinStatus(status);
}

void ViewModel::registration_all_qml() {
  LOG_TRACE("");
  QQmlContext* context = engine.rootContext();
  context->setContextProperty("ServerSettingsCardCPP", &mServerSettingsUI);

  engine.load(QUrl(QStringLiteral("../../../BackEnd/ui/impl/qml/main.qml")));
}
}  // namespace ui
