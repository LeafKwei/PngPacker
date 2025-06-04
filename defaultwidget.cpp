#include <QPainter>
#include <QPalette>
#include "defaultwidget.h"

DefaultWidget::DefaultWidget(QWidget *parent)
    : QWidget{parent}
{    
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
    
    initLayout();
    initFilling();
    initStyle();
}

void DefaultWidget::initLayout(){
    m_mainLayout = new QVBoxLayout(this);
    m_tipsLayout = new QHBoxLayout();
}

void DefaultWidget::initFilling(){
    m_tipsLayout -> addWidget(m_tips);
    m_mainLayout -> addLayout(m_tipsLayout);
}

void DefaultWidget::initStyle(){

}

void DefaultWidget::initConnection(){

}

void DefaultWidget::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
}