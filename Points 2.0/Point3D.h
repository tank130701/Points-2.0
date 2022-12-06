#pragma once
#include "Point2D.h"
#include "Z.h"
#include "Base.h"
#include <iostream>

template <class T> class Point3D : public Point2D<T>, public Z<T>, Base {
public:
	Point3D(T x, T y, T z) : Point2D <T>(x, y), Z <T>(z) {};
	void show() {
		std::cout << "X: " << this->x << ", Y: " << this->y << ", Z: " << this->z << std::endl;
	}
};


