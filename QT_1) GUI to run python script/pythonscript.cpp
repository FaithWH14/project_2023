#include "pythonscript.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QOverload>
#include <cstdio>
#include <cstdlib>

QString PYTHON_PATH = "C:\\Users\\faithwh14\\AppData\\Local\\Microsoft\\WindowsApps\\python.exe";
PythonScript::PythonScript(QWidget* parent): QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *titleLayout = new QHBoxLayout;
    QFormLayout *formLayout = new QFormLayout;
    QHBoxLayout *bodyLayout = new QHBoxLayout;

    title = new QLabel("UIAUTOMATION", this);

    titleLayout->addWidget(title);

    uiAuto = new QLabel("SELECT UIAUTOMATION OPTION TO RUN", this);
    uiAutoOption = new QComboBox(this);
    uiAutoOption->addItem("<Please Select the Value>");
    uiAutoOption->addItem("One");
    uiAutoOption->addItem("Two");
    uiAutoCommand = new QLabel(this);
    uiAutoCommand->setStyleSheet("QLabel {border: 2px solid black;}");

    connect(uiAutoOption, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PythonScript::onComboBoxChanged);

    formLayout->addRow(uiAuto, uiAutoOption);
    formLayout->addRow(uiAutoCommand);

    executeBtn = new QPushButton("Execute", this);
    connect(executeBtn, &QPushButton::clicked, this, &PythonScript::onExecuteBtnClicked);

    pipeBox = new QLabel(this);
    bodyLayout->addWidget(pipeBox);

    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(executeBtn);
    mainLayout->addLayout(bodyLayout);

    setLayout(mainLayout);
}

void PythonScript::onComboBoxChanged(int index) {
    QString selectedText = uiAutoOption->itemText(index);
    qDebug() << "THIS IS THE SELECTED TEXT VALUE: " << selectedText;

    QString index_0 = PYTHON_PATH + " python_source/python_uiauto.py -action k";
    QString index_1 = PYTHON_PATH + " python_source/python_uiauto.py -action d";

    if (selectedText == "One")
        uiAutoCommand->setText(index_0);
    else if (selectedText == "Two")
        uiAutoCommand->setText(index_1);
    else
        uiAutoCommand->setText("ERROR PLEASE CHECK");
}

void PythonScript::onExecuteBtnClicked() {
    pipeBox->clear();
    pipeOutput.clear();

    QString commandText = uiAutoCommand->text();
//    const char* commandText_1 = commandText.toUtf8().constData();
    std::string commandText_1 = commandText.toStdString();
    const char *commandText_2 = commandText_1.c_str();

    FILE *pipe = _popen(commandText_2, "r");
    if (!pipe) {
        qDebug() << "PIPE FAILED\n";
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) !=nullptr) {
        std::string bufferStr(buffer);
        pipeOutput += bufferStr;
    }

    int result = pclose(pipe);
    pipeOutput += "Command exited with result: " + std::to_string(result);

    pipeBox->setText(QString::fromStdString(pipeOutput));
}
