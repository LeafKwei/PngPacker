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
#include "code.h"

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
    QLabel *m_labResultInfo;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_bottomLayout;
    QHBoxLayout *m_optionsLayout;
    QVBoxLayout *m_infosLayout;
    
    void initUi();
    void initLayout();
    void initFilling();
    void initStyle();
    void initFileView();
    void initConnection();
    
    void showTotalInfo();
    void showResultInfo(const QString &baseInfo, Code code);
    QString cutFileName(const QString &name);
    bool isCorrectFileName(const QString &name);
    void updateTotalInfo();
    
private slots:
    void do_btnPackClicked();
    void do_btnAppendClicked();
    void do_btnDeleteClicked();
};

#endif // PACKEDWIDGET_H
