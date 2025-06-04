#include <QGuiApplication>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include "unpackeddialog.h"

UnpackedDialog::UnpackedDialog(QWidget *parent) {
    initUi();
    initConnection();
}

void UnpackedDialog::initUi(){
    m_nameLabel = new QLabel();
    m_nameEdit = new QLineEdit();
    m_picsetPathLabel = new QLabel();
    m_picsetPathEdit = new QLineEdit();
    m_picsetPathButton = new QPushButton();
    m_targetPathLabel = new QLabel();
    m_targetPathEdit = new QLineEdit();
    m_targetPathButton = new QPushButton();
    m_confirmButton = new QPushButton();
    
    m_nameLabel -> setText(tr("名称"));
    m_nameEdit -> setPlaceholderText(tr("请输入项目名称"));
    m_picsetPathLabel -> setText(tr("图集路径"));
    m_picsetPathEdit -> setPlaceholderText(tr("请输入或选择图集路径"));
    m_picsetPathButton -> setText(tr("选择"));
    m_targetPathLabel -> setText(tr("保存路径"));
    m_targetPathEdit -> setPlaceholderText(tr("请输入或选择保存路径"));
    m_targetPathButton -> setText(tr("选择"));
    m_confirmButton -> setText(tr("确定"));
    
    initLayout();
    initFilling();
    initStyle();
    
    setWindowTitle(tr("解包"));
    resize(QGuiApplication::primaryScreen() -> availableSize() * 0.5);
}

void UnpackedDialog::initLayout(){
    m_mainLayout = new QVBoxLayout(this);
    m_nameLineLayout = new QHBoxLayout();
    m_picsetPathLineLayout = new QHBoxLayout();
    m_targetPathLineLayout = new QHBoxLayout();
    m_optionLineLayout = new QHBoxLayout();
}

void UnpackedDialog::initFilling(){
    m_nameLineLayout -> addWidget(m_nameLabel);
    m_nameLineLayout -> addWidget(m_nameEdit);
    m_picsetPathLineLayout -> addWidget(m_picsetPathLabel);
    m_picsetPathLineLayout -> addWidget(m_picsetPathEdit);
    m_picsetPathLineLayout -> addWidget(m_picsetPathButton);
    m_targetPathLineLayout -> addWidget(m_targetPathLabel);
    m_targetPathLineLayout -> addWidget(m_targetPathEdit);
    m_targetPathLineLayout -> addWidget(m_targetPathButton);
    m_optionLineLayout -> addStretch(1);
    m_optionLineLayout -> addWidget(m_confirmButton);
    m_optionLineLayout -> addStretch(1);
    
    m_mainLayout -> addLayout(m_nameLineLayout);
    m_mainLayout -> addLayout(m_picsetPathLineLayout);
    m_mainLayout -> addLayout(m_targetPathLineLayout);
    m_mainLayout -> addLayout(m_optionLineLayout);
}

void UnpackedDialog::initStyle(){

}

void UnpackedDialog::initConnection(){

}

void UnpackedDialog::do_picsetPathButtonClicked(){

}

void UnpackedDialog::do_targetPathButtonClicked(){

}

void UnpackedDialog::do_confirmButtonClicked(){

}
