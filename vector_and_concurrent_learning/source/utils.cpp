#include "utils.h"

void VectorFunction::printVector(std::vector<int> vec, std::string method) {

	// METHOD A USE INDEX METHOD
	if (method == "method_a") {
		VectorFunction::printAsterisk("&");
		std::cout << "THIS IS METHOD A" << std::endl;
		VectorFunction::printAsterisk("&");

		size_t vec_length = vec.size();

		for (int i = 0; i < vec_length; i++) {
			if (i != (vec_length - 1))
				std::cout << vec[i] << ", ";
			else
				std::cout << vec[i];
		}

		std::cout << std::endl;

	}
	// METHOD B USE FOR I IN [] METHOD
	else if (method == "method_b") {
		VectorFunction::printAsterisk("&");
		std::cout << "THIS IS METHOD B" << std::endl;
		VectorFunction::printAsterisk("&");

		for (int num : vec) {
			std::cout << num;
			if (num != vec.back()) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	else {
		throw std::invalid_argument("METHOD SHOULD BE METHOD_A OR METHOD_B ONLY!");
	}

	return;
}

void VectorFunction::printAsterisk(std::string mark) {
	for (int i = 0; i < 15; i++) {
		std::cout << mark << " ";
	}
	std::cout << std::endl;

	return;
}

void MultiThread::funcA(int start, int end) {
	for (int i = start; i <= end; ++i) {
		std::cout << i << " ";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::cout << std::endl;
}