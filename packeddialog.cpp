#include <QGuiApplication>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include "packeddialog.h"

PackedDialog::PackedDialog(QWidget *parent) {
    initUi();
    initConnection();
}

void PackedDialog::initUi(){
    m_nameLabel = new QLabel();
    m_nameEdit = new QLineEdit();
    m_pngPathLabel = new QLabel();
    m_pngPathEdit = new QLineEdit();
    m_pngPathButton = new QPushButton();
    m_targetPathLabel = new QLabel();
    m_targetPathEdit = new QLineEdit();
    m_targetPathButton = new QPushButton();
    m_confirmButton = new QPushButton();
    
    m_nameLabel -> setText(tr("名称"));
    m_nameEdit -> setPlaceholderText(tr("请输入项目名称"));
    m_pngPathLabel -> setText(tr("文件路径"));
    m_pngPathEdit -> setPlaceholderText(tr("请输入或选择一个目录"));
    m_pngPathButton -> setText(tr("选择"));
    m_targetPathLabel -> setText(tr("保存路径"));
    m_targetPathEdit -> setPlaceholderText(tr("请输入或选择一个目录"));
    m_targetPathButton -> setText(tr("选择"));
    m_confirmButton -> setText(tr("确认"));
    
    initLayout();
    initFilling();
    initStyle();
    
    setWindowTitle("打包");
    resize(QGuiApplication::primaryScreen() -> availableSize() * 0.5);
}

void PackedDialog::initLayout(){
    m_mainLayout = new QVBoxLayout(this);
    m_nameLineLayout = new QHBoxLayout();
    m_pngPathLineLayout = new QHBoxLayout();
    m_targetPathLineLayout = new QHBoxLayout();
    m_optionLineLayout = new QHBoxLayout();
}

void PackedDialog::initFilling(){
    m_nameLineLayout -> addWidget(m_nameLabel);
    m_nameLineLayout -> addWidget(m_nameEdit);
    m_pngPathLineLayout -> addWidget(m_pngPathLabel);
    m_pngPathLineLayout -> addWidget(m_pngPathEdit);
    m_pngPathLineLayout -> addWidget(m_pngPathButton);
    m_targetPathLineLayout -> addWidget(m_targetPathLabel);
    m_targetPathLineLayout -> addWidget(m_targetPathEdit);
    m_targetPathLineLayout -> addWidget(m_targetPathButton);
    m_optionLineLayout -> addStretch(1);                 //通过在按钮前后添加拉伸因子限制按钮宽度
    m_optionLineLayout -> addWidget(m_confirmButton);
    m_optionLineLayout -> addStretch(1);
    
    m_mainLayout -> addLayout(m_nameLineLayout);
    m_mainLayout -> addLayout(m_pngPathLineLayout);
    m_mainLayout -> addLayout(m_targetPathLineLayout);
    m_mainLayout -> addLayout(m_optionLineLayout);
}

void PackedDialog::initStyle(){

}

void PackedDialog::initConnection(){
    connect(m_pngPathButton, SIGNAL(clicked(bool)), this, SLOT(do_pngPathButtonClicked()));
    connect(m_confirmButton, SIGNAL(clicked(bool)), this, SLOT(do_confirmButtonClicked()));
    connect(m_targetPathButton, SIGNAL(clicked(bool)), this, SLOT(do_targetPathButtonClicked()));
}

void PackedDialog::do_pngPathButtonClicked(){
    QString path = QFileDialog::getExistingDirectory(this, tr("请选择一个目录"), 
        ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    m_pngPathEdit -> setText(path);
}

void PackedDialog::do_targetPathButtonClicked(){
    QString path = QFileDialog::getExistingDirectory(this, tr("请选择一个目录"), 
            ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    m_targetPathEdit -> setText(path);
}

void PackedDialog::do_confirmButtonClicked(){
    QString name = m_nameEdit -> text();
    QString pngPath = m_pngPathEdit -> text();
    QString targetPath = m_targetPathEdit -> text();

    if(name.length() == 0 || pngPath.length() == 0 || targetPath.length() == 0){
        QMessageBox::information(nullptr, tr("提示"), tr("请输入项目名称和路径"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    
    /* 将输入框清空，然后隐藏窗口 */
    m_nameEdit -> clear();
    m_pngPathEdit -> clear();
    m_targetPathEdit -> clear();
    close();

    PackedParam param;
    param.name = name;
    param.pngPath = pngPath;
    param.targetPath = targetPath;
    emit SIGPacked(param);
}

