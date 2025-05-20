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
    m_listWidget -> addItem("NO IMAGE");
    m_stackedWidget -> addWidget(new NoImgWidget(m_stackedWidget));
    
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
    connect(m_listWidget, SIGNAL(itemRightClicked(QListWidgetItem*, QPointF)), this, SLOT(do_itemRightClicked(QListWidgetItem*, QPointF)));
}

void MainWindow::do_itemClicked(QListWidgetItem *item){
    
}

void MainWindow::do_itemRightClicked(QListWidgetItem *item, QPointF clickedPos){
    qDebug() << "Right clicked!";
    if(!item) return;
    qDebug() << "Has item!";
}
