/********************************************************************************
** Form generated from reading UI file 'unpackerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNPACKERWINDOW_H
#define UI_UNPACKERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnpackerWindow
{
public:

    void setupUi(QWidget *UnpackerWindow)
    {
        if (UnpackerWindow->objectName().isEmpty())
            UnpackerWindow->setObjectName("UnpackerWindow");
        UnpackerWindow->resize(400, 300);

        retranslateUi(UnpackerWindow);

        QMetaObject::connectSlotsByName(UnpackerWindow);
    } // setupUi

    void retranslateUi(QWidget *UnpackerWindow)
    {
        UnpackerWindow->setWindowTitle(QCoreApplication::translate("UnpackerWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UnpackerWindow: public Ui_UnpackerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNPACKERWINDOW_H
