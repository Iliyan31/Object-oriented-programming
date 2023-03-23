
#include "Person.hpp"

int main() {
	Person p("Ivan", "Ivanov");
	std::cout<<p.getName()<<"\n";
	p.setName("John");
	std::cout << p.getName() << "\n";
	std::cin >> p;
	std::cout << p.getName() << "\n";
	std::cout << p.getLastName() << "\n";
	return 0;
}