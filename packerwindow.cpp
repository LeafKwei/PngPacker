#include "packerwindow.h"
#include "ui_packerwindow.h"

PackerWindow::PackerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PackerWindow)
{
    ui->setupUi(this);
}

PackerWindow::~PackerWindow()
{
    delete ui;
}
