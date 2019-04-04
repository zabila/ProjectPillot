#ifndef SERVERIMPL_H
#define SERVERIMPL_H

#include <cstdint>
#include <map>
#include <memory>

#include "TcpServer.h"
#include "controller/Controller.h"

namespace server {
class ServerImpl {
 public:
  ServerImpl(std::shared_ptr<ctrl::Controller> ctrl);

  void addListeningPort(std::uint16_t port, std::string name);

 private:
  std::map<std::string, std::unique_ptr<TcpServer>> mListeners;
  std::shared_ptr<ctrl::Controller> mpController;
};
}  // namespace server

#endif  // SERVERIMPL_H
