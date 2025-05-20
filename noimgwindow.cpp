#include "noimgwindow.h"
#include "ui_noimgwindow.h"

noimgwindow::noimgwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::noimgwindow)
{
    ui->setupUi(this);
}

noimgwindow::~noimgwindow()
{
    delete ui;
}
