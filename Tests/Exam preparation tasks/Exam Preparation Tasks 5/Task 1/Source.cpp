#include "Matrix.hpp"

int main() {
	Matrix<int> test1(3, 3);
	test1.setAt(1, 1, 5);
	test1.setAt(1, 2, 3);
	test1.setAt(2, 1, 4);
	test1.setAt(2, 2, 1);
	test1.transpose();
	std::cout << test1.getAt(1, 2);
	return 0;
}