#pragma once

#include <cstdint>
#include <iostream>

#include "Enums.h"

struct HostAddress {
  std::string host;
  std::uint16_t port;
};

struct Message {
  network::MessageType mType;
};
