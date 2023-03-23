
#include "Header.h"

int main() {
	int n;
	printf("n= ");
	std::cin >> n;
	IntArray a(n);
	int val;
	for (int i = 0; i < n; i++) {
		printf("Element? ");
		std::cin >> val;
		if (!a.set(i, val)) {
			printf("Error while initializing the element of the array \n");
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		if (a.get(i, val)) std::cout << val << " ";
		else printf("Error while initializing the element of the array \n");
	}
	printf("\n");
	if (a.set(n, MAX_SIZE + 1)) {
		std::cout << "The element " << MAX_SIZE + 1 << " was correctly saved. \n";
	}
	else std::cout << "Error while saving the element: " << MAX_SIZE + 1;

	if (a.get(a.linearSearch(val), val)) {
		std::cout << val << " is in the array";
	}
	else std::cout << val << " is not in the array";

	a.bubbleSort();
	printf("Sorted array! \n");

	for (int i = 0; i < n; i++) {
		if (a.get(i, val)) std::cout << val << " ";
		else std::cout << "Error while getting the element. \n";
	}

	std::cout << std::endl;
	std::cout << "Element? ";
	std::cin >> val;
	std::cout << "Position of " << val << " in the array is "
		<< a.binarySearch(val) << std::endl;

	return 0;
}
