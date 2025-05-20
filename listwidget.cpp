#include <QMouseEvent>
#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent) : QListWidget(parent) {

}

void ListWidget::mousePressEvent(QMouseEvent *event){
    QListWidget::mousePressEvent(event);
    if(event -> button() == Qt::RightButton){
        QPointF qp = event -> position();
        emit itemRightClicked(itemAt(qp.x(), qp.y()), event -> globalPosition());
    }
}