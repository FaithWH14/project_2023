#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>
#include <iostream>
#include "login.h"
#include "page1.h"

class Page2: public QWidget
{
    Q_OBJECT
public:
    Page2(QWidget *parent = nullptr);

    login *loginPage;
    page1 *page1Page;
};

#endif // PAGE2_H
