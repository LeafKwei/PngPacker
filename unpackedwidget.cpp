#include <stdexcept>
#include "unpackedwidget.h"
#include "qtimagereader.h"
#include "qtimagewriter.h"
#include "packer/impl/Unpacker.hpp"
#include "packer/impl/DefaultProfileReader.hpp"

using std::exception;
using packer::Unpacker;
using packer::DefaultProfileReader;

UnpackedWidget::UnpackedWidget(const UnpackedParam &param, QWidget *parent)
    : QWidget{parent}
{
    m_param = param;
    
    initUi();
    initConnection();
}

void UnpackedWidget::initUi(){
    m_labPicsetPath = new QLabel();
    m_labTargetPath = new QLabel();
    m_labResultInfo = new QLabel();
    m_btnUnpack = new QPushButton();
    
    m_labPicsetPath -> setText(tr("图集路径：") + m_param.picsetPath);
    m_labTargetPath -> setText(tr("保存路径：") + m_param.targetPath);
    m_btnUnpack -> setText(tr("解包"));
    showResultInfo(tr("未解包"), Code::INIT);
    
    initLayout();
    initFilling();
    initStyle();
}

void UnpackedWidget::initLayout(){
    m_mainLayout = new QVBoxLayout(this);
    m_topLayout = new QVBoxLayout();
    m_bottomLayout = new QVBoxLayout();
    m_buttonsLayout = new QHBoxLayout();
}

void UnpackedWidget::initFilling(){
    m_mainLayout -> addLayout(m_topLayout);
    m_mainLayout -> addLayout(m_bottomLayout);
    m_bottomLayout -> addLayout(m_buttonsLayout);
    m_mainLayout -> setStretch(0, 5);
    m_mainLayout -> setStretch(1, 1);
    
    m_topLayout -> addStretch(1);
    m_topLayout -> addWidget(m_labPicsetPath);
    m_topLayout -> setSpacing(50);
    m_topLayout -> addWidget(m_labTargetPath);
    m_topLayout -> addStretch(1);
    m_bottomLayout -> addWidget(m_labResultInfo);
    m_buttonsLayout -> addStretch(1);
    m_buttonsLayout -> addWidget(m_btnUnpack);
    m_buttonsLayout -> addStretch(1);
}

void UnpackedWidget::initStyle(){

}

void UnpackedWidget::showResultInfo(const QString &baseInfo, Code code){
    QString info = tr("结果：");
    info += baseInfo;
    m_labResultInfo -> setText(info);
    
    QPalette pal = m_labResultInfo -> palette();
    switch(code){
        case Code::INIT:
            pal.setColor(QPalette::WindowText, QColor(0, 0, 0, 255));
            m_labResultInfo -> setPalette(pal);
            break;
        case Code::OK:
            pal.setColor(QPalette::WindowText, QColor(0, 255, 0, 255));
            m_labResultInfo -> setPalette(pal);
            break;
        case Code::ERR:
            pal.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
            m_labResultInfo -> setPalette(pal);
            break;
        default:
            break;
    }
}

void UnpackedWidget::initConnection(){
    connect(m_btnUnpack, SIGNAL(clicked(bool)), this, SLOT(do_btnUnpackClicked()));
}

void UnpackedWidget::do_btnUnpackClicked(){
    QStringList qs = m_param.picsetPath.split(u'.');
    QString prfPath = qs[0] + ".prf";
    
    try{
        Unpacker unpacker(new QtImageReader(m_param.picsetPath), new DefaultProfileReader(prfPath.toStdString()));
        unpacker.unpack();
        
        auto idList = unpacker.idList();
        for(auto &id : idList){
            QString pngPath = m_param.targetPath + "/" + QString::fromStdString(id) + ".png";
            QSharedPointer<VImage> qptr(unpacker.getImageById(id));
            QtImageWriter iwriter(pngPath);
            iwriter.write(*qptr);
        }
        
        showResultInfo("解包成功", Code::OK);
    }
    catch(exception &e){
        showResultInfo(QString("解包失败(%1)").arg(e.what()), Code::ERR);
    }
}