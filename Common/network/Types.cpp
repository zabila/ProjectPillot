#include "Types.h"

namespace network {

Address::Address() : host({}), port(INVALID_PORT) {}

Address::Address(const std::string &host, uint16_t port)
    : host(host), port(port) {}

bool Address::is_valid() const {
  auto result = (port != INVALID_PORT) || !host.empty();
  return result;
};

std::ostream &operator<<(std::ostream &stream, const Address &address) {
  stream << " host: " << address.host << " port: " << address.port;
  return stream;
}

}  // namespace network
