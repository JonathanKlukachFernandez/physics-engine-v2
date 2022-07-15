#pragma once
#include <iostream>


class Vector
{
public:
	Vector(float x, float y);

	std::string ToString();
	[[nodiscard]] float Magnitude() const;
	Vector Normalize();
private:
	float _x;
	float _y;
};