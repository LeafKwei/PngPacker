/********************************************************************************
** Form generated from reading UI file 'packerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKERWINDOW_H
#define UI_PACKERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackerWindow
{
public:

    void setupUi(QWidget *PackerWindow)
    {
        if (PackerWindow->objectName().isEmpty())
            PackerWindow->setObjectName("PackerWindow");
        PackerWindow->resize(400, 300);

        retranslateUi(PackerWindow);

        QMetaObject::connectSlotsByName(PackerWindow);
    } // setupUi

    void retranslateUi(QWidget *PackerWindow)
    {
        PackerWindow->setWindowTitle(QCoreApplication::translate("PackerWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackerWindow: public Ui_PackerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKERWINDOW_H
