#include <iostream>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class CustomTitleBar: public QWidget {
public:
    CustomTitleBar(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *titleLabel = new QLabel("Custom Title Bar");
        QPushButton *minimizeButton = new QPushButton("-");
        QPushButton *maximizeButton = new QPushButton("□");
        QPushButton *closeButton = new QPushButton("X");

        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->addWidget(titleLabel);
        layout->addWidget(minimizeButton);
        layout->addWidget(maximizeButton);
        layout->addWidget(closeButton);

        connect(minimizeButton, &QPushButton::clicked, parent, &QWidget::showMinimized);
        connect(maximizeButton, &QPushButton::clicked, this, &CustomTitleBar::toggleMaximize);
        connect(closeButton, &QPushButton::clicked, parent,  &QWidget::close);

        setStyleSheet("background-color: #333333; color: #ffffff;");
        setFixedHeight(30);
    }

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
