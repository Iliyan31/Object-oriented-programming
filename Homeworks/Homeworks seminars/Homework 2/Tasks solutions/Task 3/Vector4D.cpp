
#include "Vector4D.hpp"

Vector4D::Vector4D() {
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(0);
}

Vector4D::Vector4D(double a, double b, double c, double d) {
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vec.push_back(d);
}

double& Vector4D::operator[](const int index) {
	return this->vec[index];
}

Vector4D Vector4D::operator+(const Vector4D& vec) const
{
	Vector4D result;
	for (int i = 0; i < vec.vec.size(); i++) {
		result[i] = this->vec[i] + vec.vec[i];
	}
	return result;
}

Vector4D& Vector4D::operator+=(const Vector4D& vec)
{
	for (int i = 0; i < vec.vec.size(); i++) {
		this->vec[i] += vec.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& vec) const
{
	Vector4D result;
	for (int i = 0; i < vec.vec.size(); i++) {
		result[i] = this->vec[i] - vec.vec[i];
	}
	return result;
}

Vector4D& Vector4D::operator-=(const Vector4D& vec)
{
	for (int i = 0; i < vec.vec.size(); i++) {
		this->vec[i] -= vec.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& vec) const
{
	Vector4D result;
	for (int i = 0; i < vec.vec.size(); i++) {
		result[i] = this->vec[i] * vec.vec[i];
	}
	return result;
}

Vector4D Vector4D::operator*(const double& scalar) const
{
	Vector4D result;
	for (int i = 0; i < vec.size(); i++) {
		result[i] = this->vec[i] * scalar;
	}
	return result;
}

Vector4D& Vector4D::operator*=(const Vector4D& vec)
{
	for (int i = 0; i < vec.vec.size(); i++) {
		this->vec[i] *= vec.vec[i];
	}
	return *this;
}

Vector4D& Vector4D::operator*=(const double& scalar)
{
	for (int i = 0; i < vec.size(); i++) {
		this->vec[i] *= scalar;
	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& vec) const
{
	Vector4D result;
	for (int i = 0; i < vec.vec.size(); i++) {
		result[i] = this->vec[i] / vec.vec[i];
	}
	return result;
}

Vector4D& Vector4D::operator/=(const Vector4D& vec)
{
	for (int i = 0; i < vec.vec.size(); i++) {
		this->vec[i] /= vec.vec[i];
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D& v) const
{
	for (int i = 0; i < v.vec.size(); i++) {
		if (this->vec[i] != v.vec[i]) return false;
	}
	return true;
}

bool Vector4D::operator!=(const Vector4D& v) const
{
	for (int i = 0; i < v.vec.size(); i++) {
		if (this->vec[i] != v.vec[i]) return true;
	}
	return false;
}

bool Vector4D::operator<(const Vector4D& v) const
{
	for (int i = 0; i < v.vec.size(); i++) {
		if (this->vec[i] < v.vec[i]) return true;
		if (this->vec[i] > v.vec[i]) return false;
		if (this->vec[i] == v.vec[i]) continue;
	}
	return false;
}

bool Vector4D::operator<=(const Vector4D& v) const
{
	for (int i = 0; i < v.vec.size(); i++) {
		if (this->vec[i] > v.vec[i]) return false;
	}
	return true;
}

bool Vector4D::operator>(const Vector4D& v) const
{
	for (int i = 0; i < v.vec.size(); i++) {
		if (this->vec[i] > v.vec[i]) return true;
		if (this->vec[i] < v.vec[i]) return false;
		if (this->vec[i] == v.vec[i]) continue;
	}
	return false;
}

bool Vector4D::operator>=(const Vector4D& v) const
{
	for (int i = 0; i < v.vec.size(); i++) {
		if (this->vec[i] < v.vec[i]) return false;
	}
	return true;
}

bool Vector4D::operator!() const
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != 0) return false;
	}
	return true;
}

Vector4D Vector4D::operator-() const
{
	double value1, value2, value3, value4;
	value1 = -this->vec[0];
	value2 = -this->vec[1];
	value3 = -this->vec[2];
	value4 = -this->vec[3];
	return Vector4D(value1, value2, value3, value4);
}

void Vector4D::print() const
{
	for (int i = 0; i < 4; i++) {
		std::cout << vec[i] << " ";
	}
}