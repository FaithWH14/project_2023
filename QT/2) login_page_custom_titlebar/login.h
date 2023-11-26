#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMainWindow>

class login: public QWidget
{
    Q_OBJECT
public:
    login(QWidget *parent = nullptr);

private:
    QLabel *name;
    QLineEdit *nameLe;

    QLabel *password;
    QLineEdit *passwordLe;

    QLabel *loginInfo;
    QPushButton *loginBtn;

signals:
    void successfulLogin();

private slots:
    void onLoginBtnClicked();
};

#endif // LOGIN_H
