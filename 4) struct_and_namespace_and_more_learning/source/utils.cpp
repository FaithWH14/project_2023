#include "utils.h"

int Math::add(int x, int y) {
	return x + y;
}

void Math::draw_line(std::string mark, int length) {

	for (int i = 0; i < length; i++) {
		std::cout << mark;
	}
	std::cout << std::endl;

	return;
}