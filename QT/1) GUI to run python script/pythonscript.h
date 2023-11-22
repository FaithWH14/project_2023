#ifndef PYTHONSCRIPT_H
#define PYTHONSCRIPT_H

#include <iostream>
#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <string>

class PythonScript: public QWidget
{
    Q_OBJECT;

public:
    PythonScript(QWidget* parent = nullptr);

    QLabel* title;
    QLabel* uiAuto;
    QComboBox* uiAutoOption;
    QLabel* uiAutoCommand;
    QPushButton* executeBtn;
    QLabel* pipeBox;

    std::string pipeOutput;

private slots:
    void onComboBoxChanged(int index);
    void onExecuteBtnClicked();
};

#endif // PYTHONSCRIPT_H
