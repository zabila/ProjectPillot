#include <iostream>
#include <memory>

#include <QApplication>

#include "Common/logger/logger.h"
#include "controller/Controller.h"
#include "easylogging++.cc"
#include "server/Server.h"
#include "ui/View.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // Initialization logging
  el::Configurations conf;
  conf.set(el::Level::Trace, el::ConfigurationType::Format,
           " %datetime  [%level] %func  %msg ");
  conf.set(el::Level::Info, el::ConfigurationType::Format,
           " %datetime  [%level] %func  MSG: %msg ");
  conf.set(el::Level::Error, el::ConfigurationType::Format,
           " %datetime  [%level] %func  %loc MSG: %msg <-------");
  el::Loggers::reconfigureAllLoggers(conf);

  auto mpUI = std::make_shared<ui::View>();
  auto mpServer = std::make_shared<server::Server>();
  auto mpController = std::make_shared<ctrl::Controller>();

  mpUI->init(mpController);
  mpServer->init(mpController);
  mpController->init(mpServer, mpUI);

  return app.exec();
}
