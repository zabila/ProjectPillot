#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#include "Enums.h"

namespace network {
static uint16_t INVALID_PORT;
struct Address {
  Address();
  Address(const std::string& host, uint16_t port);

  std::string host;
  uint16_t port;

  bool is_valid() const;
};
std::ostream& operator<<(std::ostream& stream, const network::Address& address);

static std::uint32_t ClientId;

struct Message {
  network::MessageType mType;
};
}  // namespace network
