#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "page1.h"
#include "customtitlebar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    login* loginPage;
    page1* page1Page;
    CustomTitleBar* titleBar;

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
