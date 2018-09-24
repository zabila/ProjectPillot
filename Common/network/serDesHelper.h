#pragma once

#include <cstdint>

#include <QByteArray>

namespace server {
namespace serialization {

void stdString(const std::string &text, QByteArray &byteArray);
void stdInt32(std::int32_t number, QByteArray &byteArray);

} // namespace serialization
} // namespace server
