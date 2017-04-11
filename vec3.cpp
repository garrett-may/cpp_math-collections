#include "vec3.h"

namespace mth
{
	
Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f)
{
	
}	

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z)
{
	
}

Vec3::Vec3(float value) : x(value), y(value), z(value)
{
	
}

Vec3 Vec3::operator + ()
{
	return Vec3(this->x, this->y, this->z);
}

Vec3 Vec3::operator - ()
{
	return Vec3(-this->x, -this->y, -this->z);
}

float& Vec3::operator [] (int index)
{
	assert(0 <= index && index < 3);
	switch(index)
	{
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		default:
			return this->x;
	}
}

Vec3 operator + (Vec3& a, Vec3& b)
{
	return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3 operator - (Vec3& a, Vec3& b)
{
	return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vec3 operator * (Vec3& a, Vec3& b)
{
	return Vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vec3 operator / (Vec3& a, Vec3& b)
{
	return Vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}

Vec3 operator * (Vec3& a, float scalar)
{
	return Vec3(a.x * scalar, a.y * scalar, a.z * scalar);
}

Vec3 operator * (float scalar, Vec3& a)
{
	return Vec3(a.x * scalar, a.y * scalar, a.z * scalar);
}

Vec3 operator / (Vec3& a, float scalar)
{
	return Vec3(a.x / scalar, a.y / scalar, a.z / scalar);
}

float dot(Vec3& a, Vec3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 cross(Vec3& a, Vec3& b)
{
	return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

float magnitude(Vec3& a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

Vec3 normalise(Vec3& a)
{
	return a / magnitude(a);
}

std::ostream& operator << (std::ostream& os, Vec3 a)
{
	os
		<< "[" << a.x << "," << a.y << "," << a.z << "]";
	return os;
}
	
}