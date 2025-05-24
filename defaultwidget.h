#ifndef DEFAULTWIDGET_H
#define DEFAULTWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>

class DefaultWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DefaultWidget(QWidget *parent = nullptr);
    ~DefaultWidget();
    
protected:
    void paintEvent(QPaintEvent *event) override;
    
private:
    QImage *m_backgroundImage;
};

#endif // DEFAULTWIDGET_H
