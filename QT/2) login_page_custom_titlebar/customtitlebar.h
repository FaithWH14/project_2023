#ifndef CUSTOMTITLEBAR_H
#define CUSTOMTITLEBAR_H

#include <iostream>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QMouseEvent>

class CustomTitleBar: public QWidget {
    Q_OBJECT
public:
    CustomTitleBar(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *titleLabel = new QLabel("Custom Title Bar");
        QPushButton *minimizeButton = new QPushButton("-");
        QPushButton *maximizeButton = new QPushButton("□");
        QPushButton *closeButton = new QPushButton("X");

        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(titleLabel);

        QSpacerItem *spacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layout->addItem(spacer);

        layout->addWidget(minimizeButton);
        layout->addWidget(maximizeButton);
        layout->addWidget(closeButton);

        connect(minimizeButton, &QPushButton::clicked, parent, &QWidget::showMinimized);
        connect(maximizeButton, &QPushButton::clicked, this, &CustomTitleBar::toggleMaximize);
        connect(closeButton, &QPushButton::clicked, parent,  &QWidget::close);

        setStyleSheet("color: #ffffff;");
        setFixedHeight(30);
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            m_previousPos = event->globalPos();
        }
        QWidget::mousePressEvent(event);
    };
    void mouseMoveEvent(QMouseEvent *event) override {
        if (event->buttons() & Qt::LeftButton) {
            int dx = event->globalX() - m_previousPos.x();
            int dy = event->globalY() - m_previousPos.y();
            QPoint newPos = this->parentWidget()->pos() + QPoint(dx, dy);
            this->parentWidget()->move(newPos);
            m_previousPos = event->globalPos();
        }
        QWidget::mouseMoveEvent(event);
    };

private:
    QPoint m_previousPos;

private slots:
    void toggleMaximize() {
        QWidget *parentWidget = qobject_cast<QWidget *>(parent());
        if (parentWidget) {
            if (parentWidget->isMaximized()) {
                parentWidget->showNormal();
            } else {
                parentWidget->showMaximized();
            }
        }
    }
};

#endif
