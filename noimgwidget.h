#ifndef NOIMGWIDGET_H
#define NOIMGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>

namespace Ui {
class NoImgWidget;
}

class NoImgWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoImgWidget(QWidget *parent = nullptr);
    ~NoImgWidget();
    
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::NoImgWidget *ui;
    QImage m_image;
};

#endif // NOIMGWIDGET_H
