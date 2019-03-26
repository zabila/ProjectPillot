#include <iostream>
#include <memory>

#include <QGuiApplication>

#include "BackEnd/server/Server.h"
#include "Common/logger/logger.h"
#include "controller/ServerCtrl/ServerController.h"
#include "easylogging++.cc"
#include "ui/ViewModel.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  std::shared_ptr<ui::ViewModel> mpUI = std::make_shared<ui::ViewModel>();
  std::shared_ptr<server::Server> mpServer = std::make_shared<server::Server>();
  std::shared_ptr<ctrl::ServerController> mpServerCtrl =
      std::make_shared<ctrl::ServerController>();

  mpUI->setControllers(mpServerCtrl);
  mpServer->setControllers(mpServerCtrl);
  mpServerCtrl->init(mpServer, mpUI);

  return app.exec();
}
