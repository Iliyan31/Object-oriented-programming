
#ifndef HEADER
#define HEADER

#include <iostream>
#include <stdlib.h>

//const int MAX_SIZE = 20;
#define MAX_SIZE 20

class IntArray {
public:
	IntArray(int);
	~IntArray();
	IntArray(const IntArray&);
	bool set(int, int);
	bool get(int, int&);
	int linearSearch(int);
	int binarySearch(int);
	void selectionSort();
	void bubbleSort();
private:
	int* array;
	int num;
	bool isValid(int);

};

#endif // !HEADER
