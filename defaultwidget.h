#ifndef DEFAULTWIDGET_H
#define DEFAULTWIDGET_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
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
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_tipsLayout;
    QLabel *m_tips;

    void initUi();
    void initLayout();
    void initFilling();
    void initStyle();
    void initConnection();
};

#endif // DEFAULTWIDGET_H
