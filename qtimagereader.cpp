#include <QImage>
#include <QFile>
#include "qtimagereader.h"

QtImageReader::QtImageReader(const QString &path, QString id) 
    : m_path(path)
    , m_img(nullptr)
{
    m_img = new QImage(m_path);
}

QtImageReader::~QtImageReader(){
    delete m_img;
}

string QtImageReader::id(){
    if(m_id.length() == 0){
        m_id = generateIdFromPath();
    }
    return m_id.toStdString();
}

void QtImageReader::initialize(int &width, int &height){
    width = m_img -> width();
    height = m_img -> height();
}

void QtImageReader::readAllRGB(RGBA *buffer){
    int width = m_img -> width();
    int height = m_img -> height();
    
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            QRgb rgb = m_img -> pixel(x, y);
            RGBA &rrgb = buffer[y * width + x];
            rrgb.b = rgb & 0xFF;
            rrgb.g = (rgb >> 8) & 0xFF;
            rrgb.r = (rgb >> 16) & 0xFF;
            rrgb.a = (rgb >> 24) & 0xFF;
        }
    }
}

void QtImageReader::finalize(){
    
}

QString QtImageReader::generateIdFromPath(){
    QStringList parts = m_path.split(u'/');
    QString fileName = parts.at(parts.size() - 1);
    if(fileName.contains('.')){
        QString baseName = fileName.split(u'.').at(0);
        return baseName;
    }
    
    return fileName;
}
