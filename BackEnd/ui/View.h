#ifndef VIEW_H
#define VIEW_H

#include <memory>

namespace ctrl {
class Controller;
}

namespace ui {
class ViewImpl;
class View {
 public:
  explicit View();

  void init(std::shared_ptr<ctrl::Controller> ctrl);

  void setStatusConnect(bool);

 private:
  std::shared_ptr<ViewImpl> mImpl;
};
}  // namespace ui

#endif  // VIEW_H
