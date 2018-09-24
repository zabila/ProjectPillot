#include "serDesHelper.h"

#include <QDataStream>

#include "enums.h"

namespace server {
namespace serialization {

void stdString(const std::string &text, QByteArray &byteArray) {
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.startTransaction();
    out << SendType::MessagesStdString;
    out << text.c_str();
}

void stdInt32(int32_t number, QByteArray &byteArray) {
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.startTransaction();
    out << SendType::MessagesStdInt32;
    out << number;
}

} // namespace serialization
} // namespace server
