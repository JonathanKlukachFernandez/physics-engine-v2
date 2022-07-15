#include "Vector.h"

#include <sstream>
#include <string>
#include <cmath>

Vector::Vector(float x, float y)
{
	_x = x;
	_y = y;
}

std::string Vector::ToString()
{
	std::ostringstream ss;
	ss << "x:" << _x << ":" << "y:" << _y << "\n";
	return ss.str();
}

float Vector::Magnitude() const
{
	return std::sqrt(_x * _x + _y * _y);
}

Vector Vector::Normalize()
{
	const float length = Magnitude();
	return Vector(_x / length, _y / length);
}



