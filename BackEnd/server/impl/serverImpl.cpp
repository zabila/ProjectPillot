#include "serverImpl.h"

#include <QString>

namespace server {

bool ServerImpl::connectionToHostAdress(const std::string &host,
                                        uint16_t port) {
  QString qhost = QString::fromStdString(host);
  return mQtServer.connectionToHostAdress(qhost, port);
}

} // namespace server
