#include "Types.h"

bool HostAddress::isValid() { return port != 0 && host != "0.0.0.0"; }

void HostAddress::reset() {
    host = "0.0.0.0";
    port = 0;
}
