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
    m_targetPathEdit -> setPlaceholderText(tr("请输入或选择一个目录"));
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
    connect(m_picsetPathButton, SIGNAL(clicked(bool)), this, SLOT(do_picsetPathButtonClicked()));
    connect(m_targetPathButton, SIGNAL(clicked(bool)), this, SLOT(do_targetPathButtonClicked()));
    connect(m_confirmButton, SIGNAL(clicked(bool)), this ,SLOT(do_confirmButtonClicked()));
}

void UnpackedDialog::do_picsetPathButtonClicked(){
    QString path = QFileDialog::getOpenFileName(this, tr("请选择一个文件"), 
        ".", "Images (*.png)", nullptr, QFileDialog::DontResolveSymlinks);
    m_picsetPathEdit -> setText(path);
}

void UnpackedDialog::do_targetPathButtonClicked(){
    QString path = QFileDialog::getExistingDirectory(this, tr("请选择一个目录"), 
        ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    m_targetPathEdit -> setText(path);
}

void UnpackedDialog::do_confirmButtonClicked(){
    QString name = m_nameEdit -> text();
    QString picsetPath = m_picsetPathEdit -> text();
    QString targetPath = m_targetPathEdit -> text();

    if(name.length() == 0 || picsetPath.length() == 0 || targetPath.length() == 0){
        QMessageBox::information(nullptr, tr("提示"), tr("请输入项目名称和路径"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    
    /* 将输入框清空，然后隐藏窗口 */
    m_nameEdit -> clear();
    m_picsetPathEdit -> clear();
    m_targetPathEdit -> clear();
    close();

    UnpackedParam param;
    param.name = name;
    param.picsetPath = picsetPath;
    param.targetPath = targetPath;
    emit SIGUnpacked(param);
}
