#include "qtimagewriter.h"

QtImageWriter::QtImageWriter(const QString &path) 
    : m_path(path)
    , m_img(nullptr) 
{

}

QtImageWriter::~QtImageWriter(){
    delete m_img;
}

void QtImageWriter::initialize(int width, int height){
    m_img = new QImage(width, height, QImage::Format_ARGB32);
}

void QtImageWriter::writeAllRGB(const RGBA *buffer){
    int width = m_img -> width();
    int height = m_img -> height();
    
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            const RGBA &rgb = buffer[y * width + x];
            uint pix = rgb.a;
            pix = (pix << 8) | (rgb.r & 0xFF);
            pix = (pix << 8) | (rgb.g & 0xFF);
            pix = (pix << 8) | (rgb.b & 0xFF);
            m_img -> setPixel(x, y, pix);
        }
    }
}

void QtImageWriter::finalize(){
    m_img -> save(m_path);
}