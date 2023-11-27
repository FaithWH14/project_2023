#ifndef PAGE1_H
#define PAGE1_H

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include <boost/asio.hpp>

class page1: public QWidget {
    Q_OBJECT

public:
    page1(QWidget *parent = nullptr);

private:
    QPushButton *click_asio;

private slots:
    void start_asio();
};

#endif // PAGE1_H
