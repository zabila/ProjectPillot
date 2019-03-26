#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#include "Enums.h"

namespace network {
static uint16_t INVALID_PORT;
struct Adress {
  Adress();
  Adress(const std::string& host, uint16_t port);

  std::string host;
  uint16_t port;

  bool is_valid() const;
};
std::ostream& operator<<(std::ostream& stream, const network::Adress& adress);

struct Message {
  network::MessageType mType;
};
}  // namespace network
