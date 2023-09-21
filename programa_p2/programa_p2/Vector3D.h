#pragma once
#include <iostream>

using namespace std;

template <class T> class Vector3Dx;

typedef Vector3Dx<double> Vector3D; //"Cuando se llame a Vector3D por defecto se creará un Vector de double"

typedef Vector3Dx<float>  Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int>    Vector3Di;

template <class T>
class Vector3Dx
{
	T x;
	T y;
	T z;

public:
	Vector3Dx(T x = 0, T y = 0, T z = 0) :x(x), y(y), z(z) {} //Constructor por defecto y paramétrico

	//Getters y Setters
	T GetX() { return x; }
	T GetY() { return y; }
	T GetZ() { return z; }
	void SetX(const T& px) { x = px; }
	void SetY(const T& py) { y = py; }
	void SetZ(const T& pz) { z = pz; }

	//Operadores
	Vector3Dx<T> operator+(const Vector3Dx<T>& b) const { return Vector3Dx<T>(x + b.x, y + b.y, z + b.z); }
	Vector3Dx<T> operator+=(const Vector3Dx<T>& v) { x += v.x; y += v.y; z += v.z; return *this; }
	Vector3Dx<T> operator-() { return Vector3Dx<T>(-x, -y, -z); }
	Vector3Dx<T> operator-(const Vector3Dx<T>& b) { return Vector3Dx<T>(x - b.x, y - b.y, z - b.z); }
	Vector3Dx<T> operator-=(const Vector3Dx<T>& v) { x -= v.x; y -= v.y; z -= v.z; }
	Vector3Dx<T> operator/=(const T& d) { x /= d; y /= d;	z /= d; return *this; }
	Vector3Dx<T> operator/(T d) { return Vector3Dx<T>(x / d, y / d, z / d); }
	Vector3Dx<T> operator*(const T& d) { return Vector3Dx<T>(x * d, y * d, z * d); }
	Vector3Dx<T> operator*=(const T& d) { x *= d; y *= d;	z *= d; return *this; }

	// scalar product
	inline T operator * (const Vector3Dx<T>& v2) {
		Vector3Dx& v1 = *this;
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}
	inline Vector3Dx<T> crossProduct(const Vector3Dx<T>& v2) {
		Vector3Dx<T>& v1 = *this;
		return Vector3Dx<T>(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x);
	}

	inline void print() {
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}



};

