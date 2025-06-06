#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QSplitter>
#include <QTextEdit>
#include "projectlistwidget.h"
#include "mainwindow.h"
#include "defaultwidget.h"
#include "packedwidget.h"
#include "unpackedwidget.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_windowState(MainWindowState::INIT)
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
    delete m_packedDialog;
    delete m_unpackedDialog;
}

void MainWindow::initUi(){
    /* 创建视图对象 */
    m_centralWidget = centralWidget();
    m_defaultWidget = new DefaultWidget(this);
    m_projectWindows = new QStackedWidget(m_centralWidget);
    m_projectItems = new ProjectListWidget(m_centralWidget);
    m_packedDialog = new PackedDialog();
    m_unpackedDialog = new UnpackedDialog();
    m_hoverMenu = new QMenu(m_projectWindows);
    
    /* 菜单栏 */
    m_hoverMenu -> addAction(new QAction(tr("删除"), m_hoverMenu));
    
    /* 对界面的细节初始化 */
    initLayout();  //布局
    initFilling(); //填充组件
    initStyle();   //界面样式
    
    /* 根据窗口界面设置窗口 */
    setWidgetByState(MainWindowState::DEFAULT);
}

void MainWindow::initLayout(){
    m_mainLayout = new QHBoxLayout(m_centralWidget);
    m_mainLayout -> setSpacing(5);
}

void MainWindow::initFilling(){
    m_mainLayout -> addWidget(m_projectItems);
    m_mainLayout -> addWidget(m_projectWindows);
    m_mainLayout -> setStretchFactor(m_projectItems, 1);
    m_mainLayout -> setStretchFactor(m_projectWindows, 3);
}

void MainWindow::initStyle(){

}

void MainWindow::initConnection(){
    connect(m_projectItems, SIGNAL(currentRowChanged(int)), m_projectWindows, SLOT(setCurrentIndex(int)));
    connect(m_projectItems, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(do_itemClicked(QListWidgetItem*)));
    connect(m_projectItems, SIGNAL(itemRightClicked(QListWidgetItem*,QPointF)), this, SLOT(do_itemRightClicked(QListWidgetItem*,QPointF))); //wtf! 在“QListWidgetItem*,QPointF”逗号后面如果存在空格会触发signature is not normalized的警告
    connect(m_hoverMenu, SIGNAL(triggered(QAction*)), this, SLOT(do_menuActionTriggered(QAction*)));
    
    /* 上边菜单栏 */
    connect(ui -> menu_file, SIGNAL(triggered(QAction*)), this, SLOT(do_menuFileActionTriggered(QAction*)));
    connect(ui -> menu_edit, SIGNAL(triggered(QAction*)), this, SLOT(do_menuEditActionTriggered(QAction*)));
    connect(ui -> menu_help, SIGNAL(triggered(QAction*)), this, SLOT(do_menuHelpActionTriggered(QAction*)));
    
    /* 打包窗口 */
    connect(m_packedDialog, SIGNAL(SIGPacked(PackedParam)), this, SLOT(do_SIGPacked(PackedParam)));
}

void MainWindow::deleteCurrentItem(){
    QListWidgetItem *item = m_projectItems -> currentItem();
    QWidget *widget = m_projectWindows -> currentWidget();
    
    if((!item) || (!widget)) return;
    
    m_projectItems -> removeItemWidget(item);
    m_projectWindows -> removeWidget(widget);
    delete item;
    delete widget;
    
    if(m_projectItems -> count() == 0){
        setWidgetByState(MainWindowState::DEFAULT);
    }
}

void MainWindow::setWidgetByState(MainWindowState state){
    if(m_windowState == state) return;  //当窗口状态未改变时，结束设置

    switch(state){
        case MainWindowState::DEFAULT:
            goto setDefault;
        case MainWindowState::HASITEM:
            goto setHasItem;
        default:
            return;
    }

setDefault:
    m_windowState = state;
    m_centralWidget = takeCentralWidget(); //获取Widget的所属权，避免在setCentralWidget时被对象树删除
    m_defaultWidget -> setParent(this);
    setCentralWidget(m_defaultWidget);
    return;

setHasItem:
    m_windowState = state;
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

void MainWindow::do_SIGPacked(PackedParam param){
    m_projectItems -> addItem(param.name);
    m_projectWindows -> addWidget(new PackedWidget(param));
    
    if(m_projectItems -> count() > 0){
        setWidgetByState(MainWindowState::HASITEM);
    }
}

void MainWindow::do_SIGUnpacked(UnpackedParam param){
    m_projectItems -> addItem(param.name);
    m_projectWindows -> addWidget(new UnpackedWidget());
    
    if(m_projectItems -> count() > 0){
        setWidgetByState(MainWindowState::HASITEM);
    }
}

/* ---------------- OVERRIDE ------------------*/
void MainWindow::paintEvent(QPaintEvent *event){
    // QPainter painter(this);
    // painter.drawImage(0, 0, m_backgroundImage.scaled(width(), height()));
    // QMainWindow::paintEvent(event);
}