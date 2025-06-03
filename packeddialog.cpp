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
    m_nameLabel = new QLabel(this);
    m_nameEdit = new QLineEdit(this);
    m_pathLabel = new QLabel(this);
    m_pathEdit = new QLineEdit(this);
    m_pathButton = new QPushButton(this);
    m_confirmButton = new QPushButton(this);
    
    m_nameLabel -> setText(tr("名称"));
    m_nameEdit -> setPlaceholderText(tr("请输入项目名称"));
    m_pathLabel -> setText(tr("路径"));
    m_pathEdit -> setPlaceholderText(tr("请输入或选择图片目录"));
    m_pathButton -> setText(tr("选择"));
    m_confirmButton -> setText(tr("确认"));
    
    m_mainlayout = new QVBoxLayout(this);
    m_nameLineLayout = new QHBoxLayout();
    m_pathLineLayout = new QHBoxLayout();
    m_optionLineLayout = new QHBoxLayout();
    
    m_nameLineLayout -> addWidget(m_nameLabel);
    m_nameLineLayout -> addWidget(m_nameEdit);
    m_pathLineLayout -> addWidget(m_pathLabel);
    m_pathLineLayout -> addWidget(m_pathEdit);
    m_pathLineLayout -> addWidget(m_pathButton);
    m_optionLineLayout -> addStretch(1);                 //通过在按钮前后添加拉伸因子限制按钮宽度
    m_optionLineLayout -> addWidget(m_confirmButton);
    m_optionLineLayout -> addStretch(1);
    
    m_mainlayout -> addLayout(m_nameLineLayout);
    m_mainlayout -> addLayout(m_pathLineLayout);
    m_mainlayout -> addLayout(m_optionLineLayout);
    
    setWindowTitle("打包");
    resize(QGuiApplication::primaryScreen() -> availableSize() * 0.5);
}

void PackedDialog::initConnection(){
    connect(m_pathButton, SIGNAL(clicked(bool)), this, SLOT(do_pathButtonClicked()));
    connect(m_confirmButton, SIGNAL(clicked(bool)), this, SLOT(do_confirmButtonClicked()));
}

void PackedDialog::do_pathButtonClicked(){
    QString path = QFileDialog::getExistingDirectory(this, tr("请选择一个目录"), 
        ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    m_pathEdit -> setText(path);
}

void PackedDialog::do_confirmButtonClicked(){
    QString name = m_nameEdit -> text();
    QString path = m_pathEdit -> text();

    if(name.length() == 0 || path.length() == 0){
        QMessageBox::information(nullptr, tr("提示"), tr("请输入项目名称和目录"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    
    /* 将输入框清空，然后隐藏窗口 */
    m_nameEdit -> setText("");
    m_pathEdit -> setText("");
    close();

    PackedParam param;
    param.name = name;
    param.dir = path;
    emit SIGPacked(param);
}

