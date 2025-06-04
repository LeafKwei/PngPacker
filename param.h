#ifndef PARAM_H
#define PARAM_H

#include <QString>

struct PackedParam{
    QString name;
    QString pngPath;
    QString targetPath;
};

struct UnpackedParam{
    QString name;
    QString picsetPath;
    QString targetPath;
};

#endif // PARAM_H
