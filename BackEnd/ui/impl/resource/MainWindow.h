#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_FORWARD_DECLARE_CLASS(QMenu)

#include "SetingsNetworkWidget.h"

namespace ui {
class ViewImpl;
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(ui::ViewImpl *impl, QWidget *parent = nullptr);
  ~MainWindow();

 public slots:
  void showSettingsNetworkWidget();

 private:
  Ui::MainWindow *ui;
  QMenu *mainWindowMenu;

  ui::ViewImpl *mImpl;
  SetingsNetworkWidget settingsNetworkWidget;
};

#endif  // MAINWINDOW_H
