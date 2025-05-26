#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QSplitter>
#include <QTextEdit>
#include "listwidget.h"
#include "mainwindow.h"
#include "noimgwidget.h"
#include "defaultwidget.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_windowState(MainWindowState::DEFAULT)
    , m_backgroundImage(":/res/image/background.jpg")
{
    ui->setupUi(this);
    this -> setWindowState(Qt::WindowMaximized);      //窗口最大化
    initUi();
    initConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi(){
    /* 创建视图对象 */
    m_centralWidget = centralWidget();
    m_defaultWidget = new DefaultWidget(this);
    m_stackedWidget = new QStackedWidget(m_centralWidget);
    m_listWidget = new ListWidget(m_centralWidget);
    m_packedDialog = new PackedDialog();
    m_unpackedDialog = new UnpackedDialog();
    m_mainLayout = new QHBoxLayout(m_centralWidget);
    m_hoverMenu = new QMenu(m_stackedWidget);
    
    /* 初始化视图 */
    initMenuBar();
    
    /* 添加视图到布局 */
    m_mainLayout -> setSpacing(5);
    m_mainLayout -> addWidget(m_listWidget);
    m_mainLayout -> addWidget(m_stackedWidget);
    m_mainLayout -> setStretchFactor(m_listWidget, 1);
    m_mainLayout -> setStretchFactor(m_stackedWidget, 3);
    
    /* 根据窗口界面设置窗口 */
    setWidgetByState();
}

void MainWindow::initMenuBar(){
    m_hoverMenu -> addAction(new QAction(tr("删除"), m_hoverMenu));
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
    
    if(m_listWidget -> count() == 0){
        m_windowState = MainWindowState::DEFAULT;
        setWidgetByState();
    }
}

void MainWindow::setWidgetByState(){
    switch(m_windowState){
        case MainWindowState::DEFAULT:
            goto setDefault;
        case MainWindowState::HASITEM:
            goto setHasItem;
        default:
            return;
    }

setDefault:
    m_centralWidget = takeCentralWidget(); //获取Widget的所属权，避免在setCentralWidget时被对象树删除
    m_defaultWidget -> setParent(this);
    setCentralWidget(m_defaultWidget);
    return;

setHasItem:
    m_defaultWidget = takeCentralWidget();
    m_centralWidget -> setParent(this);
    setCentralWidget(m_centralWidget);
    return;    
}

MAI MainWindow::textToIndex(const QString &text){
    if(text == "打包") return MainWindowActIndex::PACK;
    if(text == "解包") return MainWindowActIndex::UNPACK;
    if(text == "退出") return MainWindowActIndex::QUIT;
    if(text == "删除") return MainWindowActIndex::DELETEITEM;
    if(text == "保存") return MainWindowActIndex::SAVE;
    
    return MainWindowActIndex::NONE;
}

/* ---------------- ACTIONS ------------------*/
void MainWindow::act_pack(){
    m_packedDialog -> show();
}

void MainWindow::act_unpck(){
    m_unpackedDialog -> show();
}

void MainWindow::act_save(){

}

void MainWindow::act_quit(){
    close();
}

void MainWindow::act_deleteItem(){
    deleteCurrentItem();
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
    switch(textToIndex(action -> text())){
        case MainWindowActIndex::DELETEITEM:
            act_deleteItem();
            break;
    }
}

void MainWindow::do_menuFileActionTriggered(QAction *action){
    switch(textToIndex(action -> text())){
        case MainWindowActIndex::PACK:
            act_pack();
            break;
        case MainWindowActIndex::UNPACK:
            act_unpck();
            break;
        case MainWindowActIndex::SAVE:
            act_save();
            break;
        case MainWindowActIndex::QUIT:
            act_quit();
            break;
    }
}

void MainWindow::do_menuEditActionTriggered(QAction *action){
    switch(textToIndex(action -> text())){
        case MainWindowActIndex::DELETEITEM:
            act_deleteItem();
            break;
    }
}

void MainWindow::do_menuHelpActionTriggered(QAction *action){
    
}

void MainWindow::do_packedButtonClicked(PackedParam param){
    if(m_listWidget -> count() > 0){
        m_windowState = MainWindowState::HASITEM;
        setWidgetByState();
    }
}

void MainWindow::do_unpackedButtonClicked(UnpackedParam param){
    if(m_listWidget -> count() > 0){
        m_windowState = MainWindowState::HASITEM;
        setWidgetByState();
    }
}

/* ---------------- OVERRIDE ------------------*/
void MainWindow::paintEvent(QPaintEvent *event){
    // QPainter painter(this);
    // painter.drawImage(0, 0, m_backgroundImage.scaled(width(), height()));
    // QMainWindow::paintEvent(event);
}