// utils.h

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <numeric>
#include <iostream>

class VectorFunction {

public:
	void printVector(std::vector<int> vec, std::string method = "method_a");

	static void printAsterisk(std::string mark = "*");

};

class MultiThread {

public:
	static void funcA(int start, int end);
};

#endif // UTILS_H