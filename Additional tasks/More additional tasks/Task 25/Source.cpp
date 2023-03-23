
#include <iostream>

void enterNumbers(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> arr[i][j];
		}
	}
}

int sumNumbers(int** arr, int rows, int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

int** transposeMatrix(int** arr, int rows, int cols) {
	if (rows != cols) {
		std::cout << "Rows must be equal to cols to transpose" << std::endl;
		return arr;
	}
	else {
		int** matrix = new int* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[rows];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				matrix[j][i] = arr[i][j];
			}
		}

		return matrix;

		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}



int validation(int& rows, int& cols) {
	if (rows <= 0) {
		std::cout << "Please enter valid rows: " << std::endl;
		std::cin >> rows;
		validation(rows, cols);
	}
	else if (cols <= 0) {
		std::cout << "Please enter valid cols: " << std::endl;
		std::cin >> cols;
		validation(rows, cols);
	}
	else if (rows <= 0 && cols <= 0) {
		std::cout << "Please enter valid coordinates: " << std::endl;
		std::cin >> rows;
		std::cin >> cols;
		validation(rows, cols);
	}
	else return 1;
}