#include "../math123/utils.h"
#include <iostream>

int main() {
	int i = 324;
	int j = 2342;

	int answer = Math123::add(i, j);

	std::cout << "I + J = " << answer << std::endl;

	return 0;
}