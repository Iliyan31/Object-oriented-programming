
#include "UniqueBox.hpp"

//int main() {
//
//	UniqueBox<int> container;
//	container += 3;
//	container += 5;
//	std::cout << container.get_counter() << std::endl;
//	container += 6;
//	container += 3;
//	std::cout << container.get_counter() << std::endl;
//	std::cout << container[1] << std::endl;
//	return 0;
//}

class A {
public:
	void speak() {
		std::cout << "Foo" << std::endl;
	}
};
class B : public A {
public:
	void speak() {
		std::cout << "Bar" << std::endl;
	}
};
int main() {
	B temp;
	temp.speak();
	A* ptr_to_temp = &temp;
	ptr_to_temp->speak();
	return 0;
}