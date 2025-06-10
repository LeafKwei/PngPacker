#ifndef QIMAGEREADER_H
#define QIMAGEREADER_H

#include <string>
#include <QString>
#include "packer/impl/ImageReader.hpp"

using packer::ImageReader;
using packer::RGBA;
using std::string;

class QImageReader : ImageReader
{
public:
    QImageReader(const QString &path, QString id=QString(""));
    ~QImageReader();
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

#endif // QIMAGEREADER_H
