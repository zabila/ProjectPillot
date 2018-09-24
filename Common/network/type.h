#pragma once

#include <cstdint>
#include <iostream>

struct HostAddress {
    std::string host = "0.0.0.0";
    std::uint16_t port = 0;

    bool isValid();
    void reset();
};
