#ifndef QTIMAGEREADER_H
#define QTIMAGEREADER_H

#include <string>
#include <QString>
#include <QImage>
#include "packer/impl/ImageReader.hpp"

using packer::ImageReader;
using packer::RGBA;
using std::string;

class QtImageReader : public ImageReader
{
public:
    QtImageReader(const QString &path, QString id=QString(""));
    ~QtImageReader();
    string id() override;
    
protected:
    void initialize(int &width, int &height) override;
    void readAllRGB(RGBA *buffer) override;
    void finalize() override;
    
private:
    QImage *m_img;
    QString m_path;
    QString m_id;
    
    QString generateIdFromPath();
};

#endif // QTIMAGEREADER_H
