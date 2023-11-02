#include "utils.h"
#include <unordered_map>
#include <list>
#include <vector>

// PRACTICE NAMESPACE HERE
namespace Math1 {
	namespace plus_or_minus {
		int add(int x, int y) {
			return x + y;
		}
	}
}

int main() {

	Math math_test;

	int x = 3;
	int y = 4;

	int answer = math_test.add(x, y);
	int answer1 = Math1::plus_or_minus::add(x, y);

	Math::draw_line();
	std::cout << "x + y = " << answer << std::endl;
	Math::draw_line();
	std::cout << "x + y using two namespace is: " << answer1 << std::endl;
	Math::draw_line();

	// PRACTICE DICTIONARY HERE
	std::unordered_map<int, std::string> dict1 = {
		{1, "Yes"},
		{0, "No"}
	};

	std::cout << "is answer == answer1: " << dict1[(answer == answer1)] << std::endl;
	Math::draw_line();

	std::cout << std::endl << std::endl;
	// REFERENCE
	int ref_a = 3;
	int& ref_aa = ref_a;

	Math::draw_line();
	std::cout << "BEFORE CHANGED" << std::endl;
	std::cout << "ref_a is: " << ref_a << std::endl;
	std::cout << "ref_aa is: " << ref_aa << std::endl;
	Math::draw_line();
	// CHANGE REF_AA FROM 3 TO 33, A WILL CHANGE ALSO AS THEY SHARE SAME MEMORY ADDRESS/ALIAS
	ref_aa = 33;

	std::cout << "AFTER CHANGED" << std::endl;
	std::cout << "ref_a is: " << ref_a << std::endl;
	std::cout << "ref_aa is: " << ref_aa << std::endl;
	Math::draw_line();

	std::cout << std::endl;
	// LIST
	Math::draw_line();
	std::list<int> list_a = { 1, 2 };
	list_a.push_back(3);
	list_a.push_front(4);
	list_a.push_back(10);

	// VECTOR
	std::vector<double> vector_b = {6.4, 4.3};
	vector_b.push_back(4.4);
	vector_b.push_back(3.3);
	vector_b.push_back(10.0);

	std::cout << "LIST_A IS: " << std::endl;
	for (int& a : list_a) {
		// IF A IS 2, CHANGE IT TO 2000, SO WE WONT SEE 2 IN THE LIST_A
		if (a == 2)
			a = 2000;
		std::cout << a;
		if (a != list_a.back()) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;

	std::cout << "VECTOR_A IS: " << std::endl;
	for (double& b : vector_b) {
		std::cout << b;
		if (b != vector_b.back()) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;

	//std::cout << "SECOND LIST ELEMENT IS: " << list_a[1] << std::endl;
	std::cout << "SECOND VECTOR ELEMENT IS: " << vector_b[1] << std::endl;

	Math::draw_line();
	std::cout << std::endl;
	Math::draw_line();
	// CONVERT LIST TO VECTOR
	std::vector<int> list2Vector(list_a.begin(), list_a.end());

	// OBSERVED THAT THE MEMORY ADDRESS OF 2, THE VALUE HAS CHANGED TO 2000
	// BECAUSE I ADD "&" TO (INT & A: LIST_A), SO IT'S NOT A COPY OF EVERY ELEMENT
	for (int& a : list2Vector) {
		std::cout << a;

		if (a != list2Vector.back())
			std::cout << ",";
	}
	std::cout << std::endl;
	Math::draw_line();

	return 0;
}