#include "login.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

login::login(QWidget *parent) : QWidget(parent)
{

    QFile file("C:\\Users\\faithwh14\\Desktop\\QT projects\\25_qt\\styles.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        setStyleSheet(styleSheet);
        file.close();
    } else {
        qDebug() << "FILE IS NOT OPEN, SOMETHING IS WRONG";
    }

    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    QFormLayout *bodyLayout = new QFormLayout;

    QPixmap image("C:\\Users\\faithwh14\\Desktop\\QT projects\\25_qt\\anime1.png");

    QLabel *imageLabel = new QLabel;
    imageLabel->setPixmap(image);

    name = new QLabel("name: ", this);
    nameLe = new QLineEdit(this);

    password = new QLabel("password: ", this);
    passwordLe = new QLineEdit(this);

    bodyLayout->addRow(name, nameLe);
    bodyLayout->addRow(password, passwordLe);

    bodyLayout->setSpacing(15);
    bodyLayout->setContentsMargins(20, 120, 20, 20);

    loginBtn = new QPushButton("login", this);
    connect(loginBtn, &QPushButton::clicked, this, &login::onLoginBtnClicked);

    verticalLayout->addLayout(bodyLayout);
    verticalLayout->addWidget(loginBtn);

    horizontalLayout->addWidget(imageLabel);
    horizontalLayout->addLayout(verticalLayout);

//    horizontalLayout->setSizeConstraint(QHBoxLayout::SetFixedSize);
}

void login::onLoginBtnClicked() {
    QString name_str = nameLe->text();
    QString password_str = passwordLe->text();

    nameLe->clear();
    passwordLe->clear();

    if (name_str == "hehe" && password_str == "hehe") {
        QMessageBox::information(this, "SUCCESS", "successfully login");
//        setFixedSize(900, 600);
        emit successfulLogin();
    } else {
        QMessageBox::information(this, "FAILURE", "failed to login");
    }
}
