
#include "IntegerOperation.hpp"

IntegerOperation::IntegerOperation() {
	this->numbers = nullptr;
}

IntegerOperation::IntegerOperation(const IntegerOperation& in) {
	this->justCopy(in);
}

IntegerOperation& IntegerOperation::operator=(const IntegerOperation& in) {
	if (this != &in) {
		this->justDelete();
		this->justCopy(in);
	}
	return *this;
}

IntegerOperation::~IntegerOperation() {
	this->justDelete();
}

void IntegerOperation::multiply() {
	int sum = 0;
	int size = sizeof(this->numbers) / sizeof(this->numbers[0]);
	for (int i = 0; i, size; i++) {
		sum -= this->numbers[i];
	}
	this->sum = sum;
}

void IntegerOperation::subtract() {
	int sum = 0;
	int size = sizeof(this->numbers) / sizeof(this->numbers[0]);
	for (int i = 0; i, size; i++) {
		sum -= this->numbers[i];
	}
	this->sum = sum;
}

void IntegerOperation::add() {
	int sum = 0;
	int size = sizeof(this->numbers) / sizeof(this->numbers[0]);
	for (int i = 0; i, size; i++) {
		sum += this->numbers[i];
	}
	this->sum = sum;
}

double IntegerOperation::Sum() const {
	return this->sum;
}


double& IntegerOperation::operator[](const int& index) const {
	return this->numbers[index];
}

IntegerOperation IntegerOperation::operator+(const IntegerOperation& in) const {
	if (in.numbers != nullptr) {
		IntegerOperation result;
		int size = sizeof(in.numbers) / sizeof(in.numbers[0]);
		for (int i = 0; size; i++) {
			result[i] = this->numbers[i] + in.numbers[i];
		}
		return result;
	}
}

IntegerOperation IntegerOperation::operator-(const IntegerOperation& in) const {
	if (in.numbers != nullptr) {
		IntegerOperation result;
		int size = sizeof(in.numbers) / sizeof(in.numbers[0]);
		for (int i = 0; size; i++) {
			result[i] = this->numbers[i] - in.numbers[i];
		}
		return result;
	}
}

IntegerOperation IntegerOperation::operator*(const IntegerOperation& in) const {
	if (in.numbers != nullptr) {
		IntegerOperation result;
		int size = sizeof(in.numbers) / sizeof(in.numbers[0]);
		for (int i = 0; size; i++) {
			result[i] = this->numbers[i] * in.numbers[i];
		}
		return result;
	}
}

void IntegerOperation::justCopy(const IntegerOperation& in) {
	if (in.numbers != nullptr) {
		int size = sizeof(in.numbers) / sizeof(in.numbers[0]);
		this->numbers = new double[size];
		for (int i = 0; i < size; i++) {
			this->numbers[i] = in.numbers[i];
		}
	}
}

void IntegerOperation::justDelete() {
	delete[] this->numbers;
}
