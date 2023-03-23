
#include "Header.h"

IntArray::IntArray(int size) {
	if (size > MAX_SIZE) {
		std::cout << size << " exceeds " << MAX_SIZE << ". \n";
		exit(1);
	}
	if (size <= 0) {
		printf("Incorrect input! \n");
		exit(1);
	}
	array = new int[size];
	if (!array) {
		printf("Error while passing the data \n");
		exit(1);
	}
	num = size;
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}

IntArray::~IntArray() {
	delete[] array;
}

IntArray::IntArray(const IntArray& p) {
	array = new int[p.num];
	if (!array) {
		printf("Error while passing the data \n");
		exit(1);
	}

	for (int i = 0; i < p.num; i++) {
		array[i] = p.array[i];
	}
	num = p.num;
}

bool IntArray::isValid(int elem) {
	return elem >= 0 && elem <= num;
}

bool IntArray::set(int elem, int value) {
	if (isValid(elem)) {
		array[elem] = value;
		return true;
	}
	return false;
}

bool IntArray::get(int elem, int& value) {
	if (isValid(elem)) {
		value = array[elem];
		return true;
	}
	return false;
}


int IntArray::linearSearch(int x) {
	int i = 0; 
	while (i < num - 1 && x != array[i]) {
		i++;
	}
	if (x == array[i]) return i;
	return num;
}

int IntArray::binarySearch(int x) {
	int middle, left = 0, right = num - 1;
	if (x < array[left]) return -1;
	if (x == array[left]) return 0;
	if (x > array[right]) return num;
	while (right - left > 1) {
		middle = (left + right) / 2;
		if (x <= array[middle]) right = middle;
		else left = middle;
	}
	return right;
}

void IntArray::selectionSort() {
	int k;
	for (int i = 0; i < num - 1; i++) {
		k = i;
		int min = array[k];
		for (int j = i + 1; j < num; j++) {
			if (array[j] < min) {
				k = j;
				min = array[k];
			}
		}
		array[k] = array[i];
		array[i] = min;
	}
}

void IntArray::bubbleSort() {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (array[i] > array[j]) std::swap(array[i], array[j]);
		}
	}
}

