/********************************************************************************
** Form generated from reading UI file 'noimgwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOIMGWIDGET_H
#define UI_NOIMGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoImgWidget
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *NoImgWidget)
    {
        if (NoImgWidget->objectName().isEmpty())
            NoImgWidget->setObjectName("NoImgWidget");
        NoImgWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(NoImgWidget);
        verticalLayout->setObjectName("verticalLayout");

        retranslateUi(NoImgWidget);

        QMetaObject::connectSlotsByName(NoImgWidget);
    } // setupUi

    void retranslateUi(QWidget *NoImgWidget)
    {
        NoImgWidget->setWindowTitle(QCoreApplication::translate("NoImgWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoImgWidget: public Ui_NoImgWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOIMGWIDGET_H
