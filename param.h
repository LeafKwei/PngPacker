#ifndef PARAM_H
#define PARAM_H

#include <QString>

struct PackedParam{
    QString name;
    QString dir;
};

typedef PackedParam UnpackedParam;

#endif // PARAM_H
