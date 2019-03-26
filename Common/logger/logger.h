#pragma once

#include "easylogging++.h"

#define LOG_MESSAGE(log_level, message) \
  LOG(log_level) << message;

#define LOG_INFO(msg) LOG_MESSAGE(INFO, msg)

#define LOG_ERROR(msg) LOG_MESSAGE(ERROR, msg)

#define LOG_TRACE(msg) LOG(TRACE) << msg;
