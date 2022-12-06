#pragma once
template <class T> class Point2D {
protected:
	T x, y;
public:
	Point2D(T x, T y) : x(x), y(y) {};
};
