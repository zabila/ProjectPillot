#ifndef VIEWIMPL_H
#define VIEWIMPL_H

#include <memory>
#include <string>

#include "controller/Controller.h"
#include "resource/MainWindow.h"

namespace ui {
class ViewImpl {
 public:
  ViewImpl(std::shared_ptr<ctrl::Controller>);
  ~ViewImpl() = default;

  void onAddListing(uint16_t port, std::string name);

 private:
  MainWindow window;

  std::shared_ptr<ctrl::Controller> mpController;
};
}  // namespace ui

#endif  // VIEWIMPL_H
