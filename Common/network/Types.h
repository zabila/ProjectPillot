#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#include "Enums.h"

namespace network {
static uint16_t INVALID_PORT;
struct Adress {
  Adress() = default;
  Adress(const Adress&) { std::cout << "Copy" << std::endl; }
  Adress(const Adress&&) { std::cout << "Move" << std::endl; }

  Adress operator=(const Adress&) {
    std::cout << "= Copy" << std::endl;
    return Adress();
  }
  Adress operator=(const Adress&&) {
    std::cout << "= Move" << std::endl;
    return Adress();
  }

  bool is_valid();
};

struct Message {
  network::MessageType mType;
};
}  // namespace network
