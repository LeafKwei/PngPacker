#ifndef UNPACKEDWIDGET_H
#define UNPACKEDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "param.h"
#include "code.h"

class UnpackedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UnpackedWidget(const UnpackedParam &param, QWidget *parent = nullptr);
    
private:
    UnpackedParam m_param;
    QLabel *m_labPicsetPath;
    QLabel *m_labTargetPath;
    QLabel *m_labResultInfo;
    QPushButton *m_btnUnpack;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_topLayout;
    QVBoxLayout *m_bottomLayout;
    QHBoxLayout *m_buttonsLayout;
    
    void initUi();
    void initLayout();
    void initFilling();
    void initStyle();
    void initConnection();
    
    void showResultInfo(const QString &baseInfo, Code code);
    
signals:

private slots:
    void do_btnUnpackClicked();
};

#endif // UNPACKEDWIDGET_H
