#ifndef SERVER_H
#define SERVER_H

#include <cstdint>
#include <memory>

namespace ctrl {
class Controller;
}

namespace server {
class ServerImpl;
class Server {
 public:
  explicit Server();

  void init(std::shared_ptr<ctrl::Controller> ctrl);

  void addListeningPort(std::uint16_t port);

 private:
  std::shared_ptr<ServerImpl> mImpl;
};
}  // namespace server

#endif  // SERVER_H
