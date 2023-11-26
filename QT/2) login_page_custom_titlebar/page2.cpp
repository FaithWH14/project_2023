#include "page2.h"
#include <QVBoxLayout>

Page2::Page2(QWidget *parent): QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    loginPage = new login(this);
    page1Page = new page1(this);

    mainLayout->addWidget(loginPage);
    mainLayout->addWidget(page1Page);
}
