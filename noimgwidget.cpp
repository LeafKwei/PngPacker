#include <QPainter>
#include "noimgwidget.h"
#include "ui_noimgwidget.h"

NoImgWidget::NoImgWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoImgWidget)
    , m_image(":/res/image/noimage.png")
{
    ui->setupUi(this);
}

NoImgWidget::~NoImgWidget()
{
    delete ui;
}

void NoImgWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawImage(0, 0, m_image.scaled(width(), height()));
}
