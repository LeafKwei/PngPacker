#ifndef PACKEDDIALOG_H
#define PACKEDDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "param.h"

class PackedDialog : public QDialog
{
    Q_OBJECT
public:
    PackedDialog();
    
private:

signals:
    void packedButtonClicked(PackedParam param);
};

#endif // PACKEDDIALOG_H
