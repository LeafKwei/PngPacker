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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void do_itemClicked(QListWidgetItem *item);
    void do_itemRightClicked(QListWidgetItem *item, QPointF clickedPos);

private:
    Ui::MainWindow *ui;
    QWidget *m_centralWidget;
    QStackedWidget *m_stackedWidget;
    ListWidget *m_listWidget;
    QHBoxLayout *m_mainLayout;
    QMenu *m_hoverMenu;
    
    void initUi();
    void initConnection();
};
#endif // MAINWINDOW_H
