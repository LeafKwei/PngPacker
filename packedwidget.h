#ifndef PACKEDWIDGET_H
#define PACKEDWIDGET_H

#include <QWidget>
#include <QVector>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "param.h"

class PackedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PackedWidget(const PackedParam &param, QWidget *parent = nullptr);

private:
    PackedParam m_param;
    QListWidget *m_wgtFileView;
    QPushButton *m_btnPack;
    QPushButton *m_btnAppend;
    QPushButton *m_btnDelete;
    QLabel *m_labTotalInfo;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_bottomLayout;
    QHBoxLayout *m_optionsLayout;
    QHBoxLayout *m_infosLayout;
    
    void initUi();
    void initLayout();
    void initFilling();
    void initStyle();
    void initFileView();
    void initConnection();
    
    QString makeTotalInfo();
    bool isCorrectName(const QString &name);
    
private slots:
    void do_btnPackClicked();
    void do_btnAppendClicked();
    void do_btnDeleteClicked();
};

#endif // PACKEDWIDGET_H
