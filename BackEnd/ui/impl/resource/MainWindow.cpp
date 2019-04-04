#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ui/impl/ViewImpl.h"

MainWindow::MainWindow(ui::ViewImpl *impl, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mImpl(impl),
      settingsNetworkWidget(impl) {
  ui->setupUi(this);
  QMenu *menu = menuBar()->addMenu(tr("&Settings"));
  menu->addAction(tr("Add server"), this,
                  &MainWindow::showSettingsNetworkWidget);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::showSettingsNetworkWidget() { settingsNetworkWidget.show(); }
