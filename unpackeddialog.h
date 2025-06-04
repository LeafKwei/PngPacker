#ifndef UNPACKEDDIALOG_H
#define UNPACKEDDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "param.h"

class UnpackedDialog : public QDialog
{
    Q_OBJECT
public:
    UnpackedDialog(QWidget *parent=nullptr);
    
private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_nameLineLayout;
    QHBoxLayout *m_picsetPathLineLayout;
    QHBoxLayout *m_targetPathLineLayout;
    QHBoxLayout *m_optionLineLayout;
    QLabel *m_nameLabel;
    QLineEdit *m_nameEdit;
    QLabel *m_picsetPathLabel;
    QLineEdit *m_picsetPathEdit;
    QPushButton *m_picsetPathButton;
    QLabel *m_targetPathLabel;
    QLineEdit *m_targetPathEdit;
    QPushButton *m_targetPathButton;
    QPushButton *m_confirmButton;
    
    void initUi();
    void initLayout();
    void initFilling();
    void initStyle();
    void initConnection();

signals:
    void SIGUnpacked(UnpackedParam param);
    
private slots:
    void do_picsetPathButtonClicked();
    void do_targetPathButtonClicked();
    void do_confirmButtonClicked();
};

#endif // UNPACKEDDIALOG_H
