#pragma once
#include "Point2D.h"
#include "Z.h"
#include "H.h"
#include "Base.h"
#include <iostream>

template <class T> class Point3Dh : protected Point2D<T>, protected Z<T>, protected H<T>, public Base {
public:
	Point3Dh(T x, T y, T z, T h) : Point2D <T>(x/h, y/h), Z <T>(z/h) , H <T>(h) {};
	void show() override{
		std::cout << "X: " << this->x << ", Y: " << this->y << ", Z: " << this->z << std::endl;
	}
};