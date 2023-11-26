#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "login.h"
#include <QStackedWidget>
#include <QVBoxLayout>

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QStackedWidget *stack = new QStackedWidget(this);

    titleBar = new CustomTitleBar(this);
    loginPage = new login(this);
    page1Page = new page1(this);

    stack->addWidget(loginPage);
    stack->addWidget(page1Page);

    stack->setCurrentWidget(loginPage);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
//    setWindowFlags(windowFlags() | Qt::Resizer);

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    QStatusBar *statusBar = new QStatusBar();
    statusBar->setFixedHeight(15);
    statusBar->setStyleSheet("background-color: #555555; color: #FFFFFF; padding: 1px");
    setStatusBar(statusBar);

    statusBar->showMessage("Ready");
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    stack->setStyleSheet("background-color: #555555");
    setCentralWidget(stack);
    setStyleSheet("background-color: #1E1E1E");
    setMenuWidget(titleBar);

    setWindowTitle("Login Page");
    resize(900, 600);

    connect(loginPage, &login::successfulLogin, [=](){
        stack->setCurrentWidget(page1Page);

        resize(1200, 900);
        setWindowTitle("Content Page");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
