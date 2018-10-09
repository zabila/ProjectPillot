#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "server/Server.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    server::Server server;
    if (server::ServerError::None == server.connectionToHostAdress("127.0.0.1", 9999)) {
        std::cout << "Server is started." << std::endl;
    }

    int a;
    std::cin >> a;

    return app.exec();
}
