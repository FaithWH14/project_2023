#include "pair.h"
#include <iostream>

int main() {
    Pair<std::string> pair1("wen hao", 26);
    std::string name = pair1.funcA();
    int age = pair1.funcB();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    return 0;
}