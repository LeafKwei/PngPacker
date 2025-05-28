#include <QGuiApplication>
#include <QScreen>
#include "packeddialog.h"

PackedDialog::PackedDialog() {
    initUi();
    initConnection();
}

void PackedDialog::initUi(){
    
    m_nameLabel = new QLabel(this);
    m_nameEdit = new QLineEdit(this);
    m_pathLabel = new QLabel(this);
    m_pathEdit = new QLineEdit(this);
    m_pathButton = new QPushButton(this);
    
    m_nameLabel -> setText("名称");
    m_nameEdit -> setPlaceholderText("请输入项目名称");
    m_pathLabel -> setText("路径");
    m_pathEdit -> setPlaceholderText("请输入或选择待打包图片所在路径");
    m_pathButton -> setText("选择");
    
    m_mainlayout = new QVBoxLayout(this);
    m_nameLineLayout = new QHBoxLayout();
    m_pathLineLayout = new QHBoxLayout();
    
    m_nameLineLayout -> addWidget(m_nameLabel);
    m_nameLineLayout -> addWidget(m_nameEdit);
    m_pathLineLayout -> addWidget(m_pathLabel);
    m_pathLineLayout -> addWidget(m_pathEdit);
    m_pathLineLayout -> addWidget(m_pathButton);
    
    m_mainlayout -> addLayout(m_nameLineLayout);
    m_mainlayout -> addLayout(m_pathLineLayout);
    
    resize(QGuiApplication::primaryScreen() -> availableSize() * 0.5);
}

void PackedDialog::initConnection(){

}
