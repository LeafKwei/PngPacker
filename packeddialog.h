#ifndef PACKEDDIALOG_H
#define PACKEDDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "param.h"

class PackedDialog : public QDialog
{
    Q_OBJECT
public:
    PackedDialog();
    
private:
    QVBoxLayout *m_mainlayout;
    QHBoxLayout *m_nameLineLayout;
    QHBoxLayout *m_pathLineLayout;
    QLabel *m_nameLabel;
    QLineEdit *m_nameEdit;
    QLabel *m_pathLabel;
    QLineEdit *m_pathEdit;
    QPushButton *m_pathButton;
    
    void initUi();
    void initConnection();

signals:
    void packedButtonClicked(PackedParam param);
};

#endif // PACKEDDIALOG_H
