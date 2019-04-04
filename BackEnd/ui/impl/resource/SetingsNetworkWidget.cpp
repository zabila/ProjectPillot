#include "SetingsNetworkWidget.h"
#include "ui_SetingsNetworkWidget.h"

#include <QString>

#include "Common/logger/logger.h"
#include "Common/macro.h"
#include "ui/impl/ViewImpl.h"

SetingsNetworkWidget::SetingsNetworkWidget(ui::ViewImpl* impl, QWidget* parent)
    : QDialog(parent), ui(new Ui::SetingsNetworkWidget), mImpl(impl) {
  ui->setupUi(this);

  connect(ui->buttonBox, &QDialogButtonBox::accepted, this,
          &SetingsNetworkWidget::onOK);
  connect(ui->buttonBox, &QDialogButtonBox::rejected, this,
          &SetingsNetworkWidget::onCancel);
}

SetingsNetworkWidget::~SetingsNetworkWidget() { delete ui; }

void SetingsNetworkWidget::onOK() {
  QString name = ui->lineEdit_name->text();
  int port = ui->lineEdit_port->text().toInt();
  mImpl->onAddListing(port, name.toStdString());
  this->hide();
}

void SetingsNetworkWidget::onCancel() {
  ui->lineEdit_name->clear();
  ui->lineEdit_port->clear();
  this->hide();
}
