#include <iostream>

#include "ssh_utils.h"

int math_operation::add(int x, int y) {
	return x + y;
}

void math_operation::double_default_x() {
	default_x = default_x * 2;

	return;
}

void math_operation::another_double_default_x() {
	int* temp_x = &default_x;
	int* temp_y = &default_y;

	std::ptrdiff_t hehe = temp_y - temp_x;

	std::cout << "TEMP_X IS: " << *temp_x << std::endl;
	std::cout << "TEMP_Y IS: " << *temp_y << std::endl;
	std::cout << "THE POINTER DIFFERENCE IS " << hehe << std::endl;
	std::cout << "THE REAL DIFFERENCE IS " << (*temp_y - *temp_x) << std::endl;
}

void math_operation::overwrite_exist_var(int &x) {

	//x = x * 2;
	x = 233;

	return;
}

int inherit_math_operation::subtract(int x, int y) {
	return y - x;
}

int inherit_math_operation::multiply(int x, int y) {
	return x * y;
}

int math_mul::multiply(int x, int y) {
	return x * y;
}