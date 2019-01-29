#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "server/Server.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  server::Server server;
  server.init();

  int a;
  std::cin >> a;

  return app.exec();
}
