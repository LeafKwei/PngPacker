#include <QPainter>
#include "defaultwidget.h"

DefaultWidget::DefaultWidget(QWidget *parent)
    : QWidget{parent}
{
    
}

DefaultWidget::~DefaultWidget(){
    
}

void DefaultWidget::paintEvent(QPaintEvent *event){
    //QPainter painter(this);
}