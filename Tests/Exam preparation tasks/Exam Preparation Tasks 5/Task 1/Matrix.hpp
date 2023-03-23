#pragma once
#include<iostream>

template<class T>
class Matrix {
public:
	Matrix();
	Matrix(const size_t& sizeRows, const size_t& sizeCols);
	Matrix(const Matrix& from);
	Matrix& operator=(const Matrix& from);
	~Matrix();

	void setAt(const size_t& x,const size_t& y, const T& element);
	T getAt(const size_t& x, const size_t& y) const;
	void transpose();

private:
	void justCopy(const Matrix& from);
	void justClear();
	void Resize();
	T** matrix;
	int sizeRows = 2; 
	int sizeCols = 2;
	int capacity = 2;
};

template<class T>
Matrix<T>::Matrix() {
	this->matrix = new T * [capacity];
	for (int i = 0; i < this->capacity; i++) {
		matrix[i] = new T[capacity];
	}
	for (int i = 0; i < this->sizeRows; i++) {
		for (int j = 0; j< this->sizeCols; j++) {
			matrix[i][j] = T();
		}
	}
}

template<class T>
 Matrix<T>::Matrix(const size_t& sizeRows, const size_t& sizeCols) {
	if (sizeRows >= sizeCols) this->capacity = sizeRows;
	if (sizeRows <= sizeCols) this->capacity = sizeCols;

	this->sizeRows = sizeRows;
	this->sizeCols = sizeCols;
	this->matrix = new T * [this->capacity];
	for (int i = 0; i < this->capacity; i++) {
	 matrix[i] = new T[this->capacity];
	}
	for (int i = 0; i < this->sizeRows; i++) {
		 for (int j = 0; j < this->sizeCols; j++) {
			 matrix[i][j] = T();
		 }
	} 	
}

template<class T>
 Matrix<T>::Matrix(const Matrix& from) {
	 this->justCopy(from);
}

template<class T>
 Matrix<T>& Matrix<T>::operator=(const Matrix& from) {
	 if (this != &from) {
		 this->justClear();
		 this->justCopy(from);
	 }
	 return *this;
}

template<class T>
 Matrix<T>::~Matrix() {
	 this->justClear();
}

 template<class T>
 void Matrix<T>::setAt(const size_t& x, const size_t& y, const T& element) {
	 if (x <= this->sizeRows && y <= this->sizeCols) {
		 for (int i = 0; i < this->sizeRows; i++) {
			 for (int j = 0; j < this->sizeCols; j++) {
				 if ((i + 1 == x) && (j + 1 == y)) {
					 matrix[i][j] = element;
				 }
			 }
		 }
	 }
 }

 template<class T>
 T Matrix<T>::getAt(const size_t& x, const size_t& y) const {
	 if (x <= this->sizeRows && y <= this->sizeCols) {
		 for (int i = 0; i < this->sizeRows; i++) {
			 for (int j = 0; j < this->sizeCols; j++) {
				 if ((i + 1 == x) && (j + 1 == y)) {
					 return matrix[i][j];
				 }
			 }
		 }
	 } 
 }

 template<class T>
 void Matrix<T>::transpose() {
	 T** newMatrix = new T * [capacity];
	 for (int i = 0; i < this->capacity; i++) {
		 newMatrix[i] = new T[capacity];
	 }
	 for (int i = 0; i < this->sizeRows; i++) {
		 for (int j = 0; j < this->sizeCols; j++) {
			 newMatrix[i][j] = matrix[i][j];
		 }
	 }
	 for (int i = 0; i < this->sizeRows; i++) {
		 for (int j = 0; j < this->sizeCols; j++) {
			  matrix[i][j] = newMatrix[j][i];
		 }
	 }
	 for (int i = 0; i < this->capacity; i++) {
		 delete[] newMatrix[i];
	 }
	 delete[] newMatrix;
 }

template<class T>
void Matrix<T>::justCopy(const Matrix& from) {
	this->capacity = from.capacity;
	this->sizeRows = from.sizeRows;
	this->sizeCols = from.sizeCols;

	this->matrix = new T * [capacity];
	for (int i = 0; i < this->capacity; i++) {
		matrix[i] = new T[capacity];
	}

	for (int i = 0; i < this->sizeRows; i++) {
		for (int j = 0; j < this->sizeCols; j++) {
			matrix[i][j] = from.matrix[i][j];
		}
	}
}

template<class T>
void Matrix<T>::justClear() {
	for (int i = 0; i < this->capacity; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

template<class T>
void Matrix<T>::Resize() {
	T**newMatrix = new T * [capacity*2];
	for (int i = 0; i < this->capacity * 2; i++) {
		newMatrix[i] = new T[capacity*2];
	}

	for (int i = 0; i < this->sizeRows; i++) {
		for (int j = 0; j < this->sizeCols; j++) {
			newMatrix[i][j] = matrix[i][j];
		}
	}
	
	this->justClear();
	this->capacity *= 2;
	this->matrix = new T * [capacity];
	for (int i = 0; i < this->capacity; i++) {
		matrix[i] = new T[capacity];
	}

	for (int i = 0; i < this->sizeRows; i++) {
		for (int j = 0; j < this->sizeCols; j++) {
			matrix[i][j] = newMatrix[i][j];
		}
	}
}
