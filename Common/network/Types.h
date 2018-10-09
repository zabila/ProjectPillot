#pragma once

#include <cstdint>
#include <iostream>

#include "Enums.h"

class HostAddress {
  public:
    bool isValid();
    void reset();

  private:
    std::string host = "0.0.0.0";
    std::uint16_t port = 0;
};

class Message {
  public:
  private:
    network::MessageType mType;
};
