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
        QString name = cutFileName(file.absoluteFilePath());
        /* 如果文件是png文件，则保存到List视图 */
        if(isCorrectFileName(name)){
            QListWidgetItem *item = new QListWidgetItem();
            item -> setText(name);
            item -> setData(Qt::UserRole, file.absoluteFilePath());
            m_wgtFileView -> addItem(item);
        }
    }
    
    updateTotalInfo();
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

QString PackedWidget::cutFileName(const QString &name){
    QStringList parts = name.split(u'/');
    return parts.at(parts.size() - 1);
}

bool PackedWidget::isCorrectFileName(const QString &name){
    return name.endsWith(tr(".png"));
}

void PackedWidget::updateTotalInfo(){
    m_labTotalInfo -> setText(makeTotalInfo());
}

/* ---------------- SLOTS ------------------*/
void PackedWidget::do_btnPackClicked(){

}

void PackedWidget::do_btnAppendClicked(){
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("选择图片"), ".", tr("Images (*.png)"));
    if(!isCorrectFileName(fileName)){
        QMessageBox::information(nullptr, tr("提示"), tr("未选择正确的文件"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    
    QListWidgetItem *item = new QListWidgetItem();
    item -> setText(cutFileName(fileName));
    item -> setData(Qt::UserRole, fileName);
    m_wgtFileView -> addItem(item);
    updateTotalInfo();
}

void PackedWidget::do_btnDeleteClicked(){
    QListWidgetItem *item = m_wgtFileView -> currentItem();
    if(item == nullptr) return;
    
    m_wgtFileView -> removeItemWidget(item);
    delete item;
    updateTotalInfo();
}
