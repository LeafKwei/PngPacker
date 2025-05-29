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
    QHBoxLayout *m_optionLineLayout;
    QLabel *m_nameLabel;
    QLineEdit *m_nameEdit;
    QLabel *m_pathLabel;
    QLineEdit *m_pathEdit;
    QPushButton *m_pathButton;
    QPushButton *m_confirmButton;
    
    void initUi();
    void initConnection();

signals:
    void packedButtonClicked(PackedParam param);
    
private slots:
    void do_pathButtonClicked();
    void do_confirmButtonClicked();
};

#endif // PACKEDDIALOG_H
