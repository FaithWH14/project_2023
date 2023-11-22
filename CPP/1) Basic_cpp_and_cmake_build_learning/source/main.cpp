#include <iostream>

#include "ssh_utils.h"

int main() {
	math_operation testing_obj;

	int x = testing_obj.default_x;
	int y = testing_obj.default_y;
	int testing_x = 345;

	int answer = testing_obj.add(x, y);

	std::cout << "***************************************" << std::endl;
	std::cout << "the answer is: " << answer << std::endl;
	std::cout << "***************************************" << std::endl;

	std::cout << "&&&&&&&&&&&&&&& ATTENTION &&&&&&&&&&&&&&&" << std::endl;
	std::cout << "BEFORE TRANSFORMED: " << testing_obj.default_x << std::endl;
	testing_obj.double_default_x();
	std::cout << "now having the double_default_x" << std::endl;
	std::cout << "AFTER TRANSFORMED: " << testing_obj.default_x << std::endl;
	std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
	testing_obj.another_double_default_x();

	std::cout << "*****************************************" << std::endl;
	std::cout << "BEFORE OVERRITE EXIST VAR: " << testing_x << std::endl;
	testing_obj.overwrite_exist_var(testing_x);
	std::cout << "AFTER OVERRITE EXIST VAR: " << testing_x << std::endl;
	std::cout << "*****************************************" << std::endl << std::endl;

	std::cout << "*****************************************" << std::endl;
	inherit_math_operation testing_obj_1;
	int i = 22;
	int j = 88;

	int add_yx = testing_obj_1.add(i, j);
	int minus_yx = testing_obj_1.subtract(i, j);
	int multiply_yx = inherit_math_operation::multiply(i, j);  // THIS WITHOUT OBJ
	std::cout << "THE ADD VALUE OF INHERITANCE IS: " << add_yx << std::endl;
	std::cout << "THE MINUS VALUE OF INHERITANCE IS: " << minus_yx << std::endl;
	std::cout << "THE MULTIPLE VALUE OF INHERITANCE IS: " << multiply_yx << std::endl;
	std::cout << "*****************************************" << std::endl;

	int multiply_yx_another_class = math_mul::multiply(i, j);
	std::cout << "\nTHE ANOTHER CLASS MULTIPLE VALUE OF INHERITANCE IS: " << multiply_yx_another_class << std::endl;
	std::cout << "THE ANOTHER CLASS MULTIPLE VALUE OF INHERITANCE IS: " << multiply_yx_another_class << std::endl;
	if (!(multiply_yx == multiply_yx_another_class))
		std::cout << "THEY ARE NOT THE SAME" << std::endl;
	else
		std::cout << "THEY ARE THE SAME" << std::endl;
	std::cout << "*****************************************" << std::endl;
}
