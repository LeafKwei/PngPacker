#include "unpackerwindow.h"
#include "ui_unpackerwindow.h"

UnpackerWindow::UnpackerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UnpackerWindow)
{
    ui->setupUi(this);
}

UnpackerWindow::~UnpackerWindow()
{
    delete ui;
}
