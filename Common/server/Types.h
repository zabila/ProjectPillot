#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#include "Enums.h"

namespace server {

using Port = uint16_t;
static const uint16_t INVALID_PORT = 0;

static std::uint32_t ClientId;

}  // namespace server
