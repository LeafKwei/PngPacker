#include "packedwidget.h"

PackedWidget::PackedWidget(const PackedParam &param, QWidget *parent)
    : QWidget{parent}
{
    m_param = param;
    
    initUi();
    initConnection();
}

void PackedWidget::initUi(){
    m_wgtFileName = new QListWidget();
    m_btnPack = new QPushButton();
    m_btnAppend = new QPushButton();
    m_btnDelete = new QPushButton();
    m_labTotalInfo = new QLabel();
    
    m_btnPack -> setText(tr("打包"));
    m_btnAppend -> setText(tr("添加"));
    m_btnDelete -> setText(tr("删除"));
    m_labTotalInfo -> setText(makeTotalInfo());
    
    initLayout();
    initFilling();
    initStyle();
}

void PackedWidget::initLayout(){
    m_mainLayout = new QVBoxLayout(this);
    m_bottomLayout = new QVBoxLayout();
    m_optionsLayout = new QHBoxLayout();
    m_infosLayout = new QHBoxLayout();
}

void PackedWidget::initFilling(){
    m_optionsLayout -> addStretch(1);
    m_optionsLayout -> addWidget(m_btnPack);
    m_optionsLayout -> addWidget(m_btnAppend);
    m_optionsLayout -> addWidget(m_btnDelete);
    m_optionsLayout -> addStretch(1);
    
    m_infosLayout -> addStretch(1);
    m_infosLayout -> addWidget(m_labTotalInfo);
    m_infosLayout -> addStretch(1);
    
    m_bottomLayout -> addLayout(m_optionsLayout);
    m_bottomLayout -> addLayout(m_infosLayout);
    
    m_mainLayout -> addWidget(m_wgtFileName);
    m_mainLayout -> addLayout(m_bottomLayout);
    m_mainLayout -> setStretch(0, 5);
    m_mainLayout -> setStretch(1, 1);
}

void PackedWidget::initStyle(){

}

void PackedWidget::initConnection(){

}

QString PackedWidget::makeTotalInfo(){
    QString info = tr("总文件数：%1");
    return info.arg(m_fileNames.size());
}
