#include <QPainter>
#include <QPalette>
#include "defaultwidget.h"

DefaultWidget::DefaultWidget(QWidget *parent)
    : QWidget{parent}
{
    /* 设置背景色 */
    QPalette palete = palette();
    palete.setColor(QPalette::Window, QColor(254, 251, 231, 255));
    setPalette(palete);
    setAutoFillBackground(true);
    
    initUi();
    initConnection();
}

DefaultWidget::~DefaultWidget(){
    
}

void DefaultWidget::initUi(){
    m_tips = new QLabel();
    
    m_tips -> setText(tr("点击'文件'创建项目"));
    m_tips -> setAlignment(Qt::AlignCenter);
    QFont font = m_tips -> font();
    font.setBold(true);
    font.setPointSize(20);
    m_tips -> setFont(font);
    
    m_mainlayout = new QVBoxLayout(this);
    m_tipslayout = new QHBoxLayout();
    
    m_tipslayout -> addWidget(m_tips);
    m_mainlayout -> addLayout(m_tipslayout);
}

void DefaultWidget::initConnection(){

}

void DefaultWidget::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
}