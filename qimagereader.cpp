#include <QImage>
#include <QFile>
#include "qimagereader.h"

QImageReader::QImageReader(const QString &path, QString id) 
    : m_path(path)
    , m_img(nullptr)
{
    m_img = new QImage(m_path);
}

QImageReader::~QImageReader(){
    delete m_img;
}

string QImageReader::id(){
    if(m_id.length() == 0){
        m_id = generateIdFromPath();
    }
    return m_id.toStdString();
}

void QImageReader::initialize(int &width, int &height){
    width = m_img -> width();
    height = m_img -> height();
}

void QImageReader::readAllRGB(RGBA *buffer){
    int w = m_img -> width;
    int h = m_img -> height;
    
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            QRgb rgb = m_img -> pixel(x, y);
            RGBA &rrgb = buffer[y * w + x];
            rrgb.b = rgb & 0xFF;
            rrgb.g = (rgb >> 8) & 0xFF;
            rrgb.r = (rgb >> 16) & 0xFF;
            rrgb.a = (rgb >> 24) & 0xFF;
        }
    }
}

void QImageReader::finalize(){
    
}

QString QImageReader::generateIdFromPath(){
    QStringList parts = m_path.split(u'/');
    QString fileName = parts.at(parts.size() - 1);
    if(fileName.contains('.')){
        QString baseName = fileName.split(u'.').at(0);
        return baseName;
    }
    
    return fileName;
}
