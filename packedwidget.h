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
    QVector<QString> m_fileNames;
    QListWidget *m_wgtFileName;
    QPushButton *m_btnPack;
    QPushButton *m_btnDelete;
    QPushButton *m_btnAppend;
    QLabel *m_labTotalInfo;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_bottomLayout;
    QHBoxLayout *m_optionsLayout;
    QHBoxLayout *m_infosLayout;
    
    void initUi();
    void initLayout();
    void initFilling();
    void initStyle();
    void initConnection();
    
    QString makeTotalInfo();

signals:
};

#endif // PACKEDWIDGET_H
