#include "ServerController.h"

#include "BackEnd/server/Server.h"
#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "ui/ViewModel.h"

namespace ctrl {

void ServerController::init(const std::shared_ptr<server::Server>& server,
                            const std::shared_ptr<ui::ViewModel>& ui) {
  mpServer = server;
  mpViewer = ui;
}

void ServerController::connectToServer(const network::Adress& adress) {
  LOG_TRACE("");
  REQUIRE(adress.is_valid(), "Server adress invalid.");
  REQUIRE(mpServer, "Server invalid.");

  mpServer->setHostAddress(adress);
  network::ServerError error = mpServer->connectionToHostAddress();

  REQUIRE(mpViewer, "mpViewer invalid.");
  mpViewer->sendServerStatus(error == network::ServerError::None);
}

void ServerController::onConnectToServer(bool status) {
  LOG_TRACE("");
  REQUIRE(mpViewer, "UI invalid.");
  mpViewer->sendServerStatus(status);
}

}  // namespace ctrl
