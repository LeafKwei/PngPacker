#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>
#include "listwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class MainWindowState{DEFAULT, HASITEM};
enum class MainWindowActIndex{NONE, PACK, UNPACK, SAVE, QUIT, DELETEITEM};
typedef MainWindowActIndex MAI; //缩短函数原型

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void do_itemClicked(QListWidgetItem *item);
    void do_itemRightClicked(QListWidgetItem *item, QPointF clickedPos);
    void do_menuActionTriggered(QAction *action);
    void do_menuFileActionTriggered(QAction *action);
    void do_menuEditActionTriggered(QAction *action);
    void do_menuHelpActionTriggered(QAction *action);

private:
    Ui::MainWindow *ui;
    QWidget *m_defaultWidget;
    QWidget *m_centralWidget;
    QStackedWidget *m_stackedWidget;
    ListWidget *m_listWidget;
    QHBoxLayout *m_mainLayout;
    QMenu *m_hoverMenu;
    MainWindowState m_windowState;
    
    void initUi();
    void initMenuBar();
    void initConnection();
    void setWidgetByState();
    void deleteCurrentItem();
    MAI textToIndex(const QString &text);
    
    void act_pack();
    void act_unpck();
    void act_save();
    void act_quit();
    void act_deleteItem();
};
#endif // MAINWINDOW_H
