
#include "Header.h"

int main() {
	L* p;
	p = nullptr;
	
	for (int i = 0; i < 2; i++) {
		switch (i) {
		case 0: p = new L(8); break;
		case 1: p = new L(1, 3.5);
		}
		if (!p) {
			printf("Error while passing memorry");
			return -1;
		}
		p->display();
		delete p;
	}

	return 0;
}

