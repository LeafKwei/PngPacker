#ifndef QTIMAGEWRITER_H
#define QTIMAGEWRITER_H

#include <QString>
#include <QImage>
#include "packer/core/VImage.hpp"
#include "packer/impl/ImageWriter.hpp"

using packer::ImageWriter;
using packer::RGBA;
using packer::VImage;

class QtImageWriter : public ImageWriter
{
public:
    QtImageWriter(const QString &path);
    ~QtImageWriter();
    
protected:
    void initialize(int width, int height) override;
    void writeAllRGB(const RGBA *buffer) override;
    void finalize() override;
    
private:
    QString m_path;
    QImage *m_img;
};

#endif // QTIMAGEWRITER_H
