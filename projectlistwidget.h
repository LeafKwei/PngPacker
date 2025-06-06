#ifndef PROJECTLISTWIDGET_H
#define PROJECTLISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>

class ProjectListWidget : public QListWidget
{
    Q_OBJECT
public:
    ProjectListWidget(QWidget *parent=nullptr);
        
protected:
    void mousePressEvent(QMouseEvent *event) override;
    
signals:
    void itemRightClicked(QListWidgetItem *item, QPointF clickedPos);
    void itemRemoved();
};

#endif // PROJECTLISTWIDGET_H
