#pragma once

#include "logger/logger.h"

#define REQUIRE(arg, msg) \
  if (!arg) {             \
    LOG_ERROR(msg);       \
    return;               \
  }

#define REQUIRE_R(arg, msg, return_value) \
  if (!arg) {                             \
    LOG_ERROR(msg);                       \
    return return_value;                  \
  }
