#include <QMouseEvent>
#include "projectlistwidget.h"

ProjectListWidget::ProjectListWidget(QWidget *parent) : QListWidget(parent) {

}

void ProjectListWidget::mousePressEvent(QMouseEvent *event){
    QListWidget::mousePressEvent(event);
    if(event -> button() == Qt::RightButton){
        QPointF qp = event -> position();
        emit itemRightClicked(itemAt(qp.x(), qp.y()), event -> globalPosition());
    }
}