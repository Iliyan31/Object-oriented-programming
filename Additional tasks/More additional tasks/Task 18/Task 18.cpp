
#include "Header.h"

int main() {
	N* p = nullptr;

	for (int i = 0; i < 2; i++) {
		switch (i) {
		case 0: p = new N(8); break;
		case 1: p = new N(1, 3.5);
		}
		if (!p) {
			printf("Error while passing the data \n");
			return -1;
		}
		p->display();
		delete p;
	}

	return 0;
}
