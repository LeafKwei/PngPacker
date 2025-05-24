#include <QPainter>
#include "defaultwidget.h"

DefaultWidget::DefaultWidget(QWidget *parent)
    : QWidget{parent}
    , m_backgroundImage{nullptr}
{
    m_backgroundImage = new QImage(":/res/image/noimage.png");
}

DefaultWidget::~DefaultWidget(){
    delete m_backgroundImage;
}

void DefaultWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawImage(0, 0, m_backgroundImage -> scaled(width(), height()));
}