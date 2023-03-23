
#include <iostream>
#include "Header.h"

int main() {
	int rows;
	int cols;
	std::cin >> rows >> cols;
	validation(rows, cols);
	
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	enterNumbers(arr, rows, cols);
	std::cout << sumNumbers(arr, rows, cols) << std::endl;
	
	int** ptr;
	ptr = transposeMatrix(arr, rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << ptr[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}