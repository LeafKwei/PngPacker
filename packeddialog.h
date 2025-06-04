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
    PackedDialog(QWidget *parent=nullptr);
    
private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_nameLineLayout;
    QHBoxLayout *m_pngPathLineLayout;
    QHBoxLayout *m_targetPathLineLayout;
    QHBoxLayout *m_optionLineLayout;
    QLabel *m_nameLabel;
    QLineEdit *m_nameEdit;
    QLabel *m_pngPathLabel;
    QLineEdit *m_pngPathEdit;
    QPushButton *m_pngPathButton;
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
    void SIGPacked(PackedParam param);
    
private slots:
    void do_pngPathButtonClicked();
    void do_targetPathButtonClicked();
    void do_confirmButtonClicked();
};

#endif // PACKEDDIALOG_H
