#include "utils.h"
#include <iostream>
#include <vector>
#include <thread>

int main() {

	std::vector<int> vector_a = { 1, 2, 3 };

	try {
		VectorFunction vectorFunction;

		VectorFunction::printAsterisk();
		vectorFunction.printVector(vector_a, "method_b");
		VectorFunction::printAsterisk();
	}
	
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		VectorFunction::printAsterisk();
	}

	std::cout << std::endl << std::endl << std::endl;

	// MULTITHREADING REGION
	using mt = MultiThread;
	std::thread thread1(mt::funcA, 1, 5);

	//std::this_thread::sleep_for(std::chrono::milliseconds(900));
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	std::thread thread2(mt::funcA, 11, 15);

	thread1.join();
	thread2.join();

	return 0;
}
