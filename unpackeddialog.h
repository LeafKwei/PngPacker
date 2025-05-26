#ifndef UNPACKEDDIALOG_H
#define UNPACKEDDIALOG_H

#include <QDialog>
#include "param.h"

class UnpackedDialog : public QDialog
{
    Q_OBJECT
public:
    UnpackedDialog();
    
signals:
    void unpackedButtonClicked(UnpackedParam param);
};

#endif // UNPACKEDDIALOG_H
