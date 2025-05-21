#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>

class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    ListWidget(QWidget *parent=nullptr);
        
protected:
    void mousePressEvent(QMouseEvent *event) override;
    
signals:
    void itemRightClicked(QListWidgetItem *item, QPointF clickedPos);
    void itemRemoved();
};

#endif // LISTWIDGET_H
