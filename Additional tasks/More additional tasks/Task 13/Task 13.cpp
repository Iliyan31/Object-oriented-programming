
#include "Header.h"

Complex Complex::Horner(int size, Complex arr[], Complex x) {
	Complex c = arr[0];
	for (int i = 1; i < size; i++) {
		s = s.mult(x).sum(arr[i]);
	}
	return s;
}