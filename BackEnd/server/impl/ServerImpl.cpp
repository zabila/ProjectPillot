#include "ServerImpl.h"

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "TcpServer.h"

namespace server {

ServerImpl::ServerImpl() {
  LOG_TRACE("");
  mTcpServer = std::make_unique<network::TcpServer>();
}

void ServerImpl::setControllers(
    const std::shared_ptr<ctrl::ServerController> &arg) {
  LOG_TRACE("");
  mpServerController = arg;
}

bool ServerImpl::connectionToHostAdress() {
  LOG_TRACE("");
  REQUIRE_R(mTcpServer, "mTcpServer ivalid.", false);
  return mTcpServer->StartServer();
}

bool ServerImpl::sendToClientStdString(const std::string &text) {
  LOG_TRACE("");
  if (text.empty()) return false;
  return true;
}

bool ServerImpl::sendToClientStdInt32(int32_t) {
  LOG_TRACE("");
  return true;
}

void ServerImpl::setHostAddress(const network::Adress &adress) {
  LOG_TRACE("");
  REQUIRE(mTcpServer, "mTcpServer ivalid.")
  mTcpServer->setConnectAdress(adress);
}

}  // namespace server
