#include "page1.h"

page1::page1(QWidget *parent): QWidget(parent) {
    resize(400, 300);

    QLabel *title = new QLabel("PAGE1", this);
    title->move(230, 130);
}

// ADD DARK AND WHITE MODE FEATURE
// ADD OPENCV OR ASIO INTO QT AND SEE IF IT CAN WORK
// REFER TO ONLINE CONTENT DESIGN
// ADD MENU BAR INSTEAD OF PREVIOUS PAGE OR NEXT PAGE
