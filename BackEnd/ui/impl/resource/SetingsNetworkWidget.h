#ifndef SETINGSNETWORKWIDGET_H
#define SETINGSNETWORKWIDGET_H

#include <QDialog>

namespace ui {
class ViewImpl;
}

namespace Ui {
class SetingsNetworkWidget;
}

class SetingsNetworkWidget : public QDialog {
  Q_OBJECT

 public:
  explicit SetingsNetworkWidget(ui::ViewImpl *impl, QWidget *parent = nullptr);
  ~SetingsNetworkWidget();

 public slots:
  void onOK();
  void onCancel();

 private:
  Ui::SetingsNetworkWidget *ui;
  ui::ViewImpl *mImpl;
};

#endif  // SETINGSNETWORKWIDGET_H
