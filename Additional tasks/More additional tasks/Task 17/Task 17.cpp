
#include "Header.h"

int main() {
	M* p;
	p = nullptr;
	for (int i = 0; i < 2; i++) {
		switch (i) {
		case 0: p = new M(5); break;
		case 1: p = new M(i, i + 1.5);
		}
		if (!p) {
			printf("Error while passing the memory! \n");
			return -1;
		}
		p->display();
		delete p;
	}
	return 0;
}
