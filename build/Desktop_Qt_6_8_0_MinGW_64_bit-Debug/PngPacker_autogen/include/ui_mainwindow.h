/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *act_pack;
    QAction *act_unpack;
    QAction *act_quit;
    QAction *act_save;
    QAction *action;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_edit;
    QMenu *menu_help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icon/mainwindow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        act_pack = new QAction(MainWindow);
        act_pack->setObjectName("act_pack");
        act_unpack = new QAction(MainWindow);
        act_unpack->setObjectName("act_unpack");
        act_quit = new QAction(MainWindow);
        act_quit->setObjectName("act_quit");
        act_save = new QAction(MainWindow);
        act_save->setObjectName("act_save");
        action = new QAction(MainWindow);
        action->setObjectName("action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName("menu_file");
        menu_edit = new QMenu(menubar);
        menu_edit->setObjectName("menu_edit");
        menu_help = new QMenu(menubar);
        menu_help->setObjectName("menu_help");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_edit->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(act_pack);
        menu_file->addAction(act_unpack);
        menu_file->addAction(act_save);
        menu_file->addAction(act_quit);
        menu_edit->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PngPacker", nullptr));
        act_pack->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\214\205", nullptr));
#if QT_CONFIG(shortcut)
        act_pack->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        act_unpack->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\214\205", nullptr));
#if QT_CONFIG(shortcut)
        act_unpack->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        act_quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        act_quit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        act_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        act_save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
#if QT_CONFIG(shortcut)
        action->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_edit->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_help->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
