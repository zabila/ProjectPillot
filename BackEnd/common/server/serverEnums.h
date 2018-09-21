#pragma once

#include <iostream>

namespace server {
enum ServerError {
  None = 0,
  Error,
  NotConnected,
};
}  // namespace server

std::ostream& operator<<(std::ostream& os, server::ServerError sr);
