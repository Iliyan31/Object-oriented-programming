
#include "NamedObject.hpp"

int main() {

	NamedObject<int> s("name", 5, 6);
	NamedObjectArray<int> p;
	p.getAllObjects();
	p.addObject(s);

	return 0;
}