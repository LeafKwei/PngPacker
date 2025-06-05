#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "packedwidget.h"

PackedWidget::PackedWidget(const PackedParam &param, QWidget *parent)
    : QWidget{parent}
{
    m_param = param;
    
    initUi();
    initFileView();
    initConnection();
}

void PackedWidget::initUi(){
    m_wgtFileView = new QListWidget();
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
    
    m_mainLayout -> addWidget(m_wgtFileView);
    m_mainLayout -> addLayout(m_bottomLayout);
    m_mainLayout -> setStretch(0, 5);
    m_mainLayout -> setStretch(1, 1);
}

void PackedWidget::initStyle(){

}

void PackedWidget::initFileView(){
    QDir dir(m_param.pngPath);
    if(!dir.exists()){
        return;
    }
    
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    QFileInfoList files = dir.entryInfoList();
    
    /* 遍历每个文件 */
    for(auto &file : files){
        /* 如果文件是png文件，则保存到List视图 */
        if(isCorrectName(file.baseName())){
            QListWidgetItem *item = new QListWidgetItem();
            item -> setText(file.baseName());
            m_wgtFileView -> addItem(item);
        }
    }
    
    m_labTotalInfo -> setText(makeTotalInfo());
}

void PackedWidget::initConnection(){
    connect(m_btnPack, SIGNAL(clicked(bool)), this, SLOT(do_btnPackClicked()));
    connect(m_btnAppend, SIGNAL(clicked(bool)), this, SLOT(do_btnAppendClicked()));
    connect(m_btnDelete, SIGNAL(clicked(bool)), this, SLOT(do_btnDeleteClicked()));
}

QString PackedWidget::makeTotalInfo(){
    QString info = tr("总文件数：%1   保存路径：%2");
    return info.arg(m_wgtFileView -> count()).arg(m_param.targetPath);
}

bool PackedWidget::isCorrectName(const QString &name){
    return true;
}

/* ---------------- SLOTS ------------------*/
void PackedWidget::do_btnPackClicked(){

}

void PackedWidget::do_btnAppendClicked(){
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("选择图片"), ".", tr("Images (*.png)"));
    if(!isCorrectName(fileName)){
        QMessageBox::information(nullptr, tr("提示"), tr("未选择正确的文件"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    
    QListWidgetItem *item = new QListWidgetItem();
    item -> setText(fileName);
    m_wgtFileView -> addItem(item);
}

void PackedWidget::do_btnDeleteClicked(){

}
