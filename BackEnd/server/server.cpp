#include "server.h"

#include "impl/serverImpl.h"

namespace server {
Server::Server() { mServerImpl.reset(new ServerImpl); }

Server::~Server() {}

ServerError Server::connectionToHostAdress(const std::string &host,
                                           uint16_t port) {
  if (!mServerImpl) {
    qDebug() << "mServerImpl is invalid.";
    return ServerError::Error;
  }
  mServerImpl->connectionToHostAdress(host, port);
  return ServerError::None;
}
} // namespace server
