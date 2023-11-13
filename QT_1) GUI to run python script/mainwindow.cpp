#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStackedWidget *stack = new QStackedWidget(this);

    uiauto = new PythonScript(this);

    stack->addWidget(uiauto);

    stack->currentWidget();

    setCentralWidget(stack);
}

MainWindow::~MainWindow()
{
    delete ui;
}

