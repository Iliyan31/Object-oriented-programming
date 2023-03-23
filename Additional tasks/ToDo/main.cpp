
#include "ToDo.h"

int main() {
	ToDo t("zadacha 1", 1);
	ToDo s;
	s = t;
	s.print();

	return 0;
}