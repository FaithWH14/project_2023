#include <iostream>

class math_operation {

public:

	int add(int x, int y);

	void double_default_x();
	void another_double_default_x();

	void overwrite_exist_var(int& x);

	int default_x = 33;
	int default_y = 673;
};

class inherit_math_operation : public math_operation {

public:
	int subtract(int x, int y);

	static int multiply(int x, int y);
};

class math_mul {
	
public:
	static int multiply(int x, int y);
};