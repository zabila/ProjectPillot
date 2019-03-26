#include "Types.h"

namespace network {

Adress::Adress() : host({}), port(INVALID_PORT) {}

Adress::Adress(const std::string &host, uint16_t port)
    : host(host), port(port) {}

bool Adress::is_valid() const {
  auto result = (port != INVALID_PORT) || !host.empty();
  return result;
};

std::ostream &operator<<(std::ostream &stream, const Adress &adress) {
  stream << " host: " << adress.host << " port: " << adress.port;
  return stream;
}

}  // namespace network
