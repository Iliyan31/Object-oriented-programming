
#ifndef INTEGEROPERATION
#define INTEGEROPERATION
#include <iostream>

class IntegerOperation {
public:
	IntegerOperation();
	IntegerOperation(const IntegerOperation& in);
	IntegerOperation& operator=(const IntegerOperation& in);
	~IntegerOperation();
	void multiply();
	void subtract();
	void add();
	double Sum() const;

	double& operator[](const int& index) const;
	IntegerOperation operator+(const IntegerOperation& in) const;
	IntegerOperation operator-(const IntegerOperation& in) const;
	IntegerOperation operator*(const IntegerOperation& in) const;

private:
	double* numbers;
	double sum;
	void justCopy(const IntegerOperation& in);
	void justDelete();
};

#endif // !INTEGEROPERATION

