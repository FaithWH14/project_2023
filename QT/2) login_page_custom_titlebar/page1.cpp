#include "page1.h"
#include <QVBoxLayout>

page1::page1(QWidget *parent): QWidget(parent) {

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *title = new QLabel("PAGE1", this);
    title->move(230, 130);

    click_asio = new QPushButton("click asio", this);

    mainLayout->addWidget(title);
    mainLayout->addWidget(click_asio);

    connect(click_asio, &QPushButton::clicked, this, &page1::start_asio);
}

void page1::start_asio() {

    qDebug() << "check if asio work or not, wait for 2 seconds";
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(2));
    t.wait();
    qDebug() << "2 Seconds reached";

}

// ADD DARK AND WHITE MODE FEATURE
// ADD OPENCV OR ASIO INTO QT AND SEE IF IT CAN WORK
// REFER TO ONLINE CONTENT DESIGN
// ADD MENU BAR INSTEAD OF PREVIOUS PAGE OR NEXT PAGE
