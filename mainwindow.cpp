#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QSplitter>
#include <QTextEdit>
#include "listwidget.h"
#include "mainwindow.h"
#include "noimgwidget.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setWindowState(Qt::WindowMaximized);
    initUi();
    initConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi(){
    /* 创建视图对象 */
    m_centralWidget = this -> centralWidget();
    m_stackedWidget = new QStackedWidget(m_centralWidget);
    m_listWidget = new ListWidget(m_centralWidget);
    m_mainLayout = new QHBoxLayout(m_centralWidget);
    m_hoverMenu = new QMenu(m_centralWidget);
    
    /* 初始化视图 */
    m_listWidget -> addItem("主页");
    m_stackedWidget -> addWidget(new NoImgWidget(m_stackedWidget));
    m_hoverMenu -> addAction(new QAction(tr("删除"), m_hoverMenu));
    
    /* 添加视图到布局 */
    m_mainLayout -> setSpacing(5);
    m_mainLayout -> addWidget(m_listWidget);
    m_mainLayout -> addWidget(m_stackedWidget);
    m_mainLayout -> setStretchFactor(m_listWidget, 1);
    m_mainLayout -> setStretchFactor(m_stackedWidget, 3);
}

void MainWindow::initConnection(){
    connect(m_listWidget, SIGNAL(currentRowChanged(int)), m_stackedWidget, SLOT(setCurrentIndex(int)));
    connect(m_listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(do_itemClicked(QListWidgetItem*)));
    connect(m_listWidget, SIGNAL(itemRightClicked(QListWidgetItem*,QPointF)), this, SLOT(do_itemRightClicked(QListWidgetItem*,QPointF))); //wtf! 在“QListWidgetItem*,QPointF”逗号后面如果存在空格会触发signature is not normalized的警告
    connect(m_hoverMenu, SIGNAL(triggered(QAction*)), this, SLOT(do_menuActionTriggered(QAction*)));
    
    /* 上边菜单栏 */
    connect(ui -> menu_file, SIGNAL(triggered(QAction*)), this, SLOT(do_menuFileActionTriggered(QAction*)));
    connect(ui -> menu_edit, SIGNAL(triggered(QAction*)), this, SLOT(do_menuEditActionTriggered(QAction*)));
    connect(ui -> menu_help, SIGNAL(triggered(QAction*)), this, SLOT(do_menuHelpActionTriggered(QAction*)));
}

void MainWindow::deleteCurrentItem(){
    QListWidgetItem *item = m_listWidget -> currentItem();
    QWidget *widget = m_stackedWidget -> currentWidget();
    
    if((!item) || (!widget)) return;
    
    m_listWidget -> removeItemWidget(item);
    m_stackedWidget -> removeWidget(widget);
    delete item;
    delete widget;
}

/* ---------------- SLOTS ------------------*/

void MainWindow::do_itemClicked(QListWidgetItem *item){
    //暂时保留
}

void MainWindow::do_itemRightClicked(QListWidgetItem *item, QPointF clickedPos){
    if(!item) return; //在无item的位置右键时不做任何操作
    m_hoverMenu -> exec(clickedPos.toPoint());
}

void MainWindow::do_menuActionTriggered(QAction *action){
    if(action -> text() == tr("删除")){  //点击删除按钮
        deleteCurrentItem();
    }
}

void MainWindow::do_menuFileActionTriggered(QAction *action){
    if(action -> text() == tr("打包")){
        m_listWidget -> addItem("新建打包");
        m_stackedWidget -> addWidget(new NoImgWidget(m_stackedWidget));
    }
    else if(action -> text() == tr("解包")){
    
    }
    else if(action -> text() == tr("退出")){
        close();
    }
    else
    {
        
    }
}

void MainWindow::do_menuEditActionTriggered(QAction *action){
    if(action -> text() == tr("删除")){
        deleteCurrentItem();
    }
}

void MainWindow::do_menuHelpActionTriggered(QAction *action){
    
}

