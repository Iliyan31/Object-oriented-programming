#pragma once

// Add all other required methods and fields of the class.
#include <vector>
#include <iostream>        
class Vector4D {

public:

    Vector4D();
    Vector4D(double, double, double, double);
    
    
    double& operator[](const int index);
    Vector4D operator+(const Vector4D& vec) const;
    Vector4D& operator+=(const Vector4D& vec);
    Vector4D operator-(const Vector4D& vec) const;
    Vector4D& operator-=(const Vector4D& vec);
    Vector4D operator*(const Vector4D& vec) const;
    Vector4D operator*(const double& scalar) const;
    Vector4D& operator*=(const Vector4D& vec);
    Vector4D& operator*=(const double& scalar);
    Vector4D operator/(const Vector4D& vec) const;
    Vector4D& operator/=(const Vector4D& vec);
    bool operator==(const Vector4D& v) const;
    bool operator!=(const Vector4D& v) const;
    bool operator<(const Vector4D& v) const;
    bool operator<=(const Vector4D& v) const;
    bool operator>(const Vector4D& v) const;
    bool operator>=(const Vector4D& v) const;
    bool operator!() const;
    Vector4D operator-() const;
    

    void print() const;                         
private:
    std::vector<double> vec;
};