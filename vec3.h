#pragma once

#include <math.h>
#include <assert.h>
#include <iostream>

namespace mth
{

class Vec3
{
public:
	float x;
	float y;
	float z;
	
	Vec3();
	Vec3(float, float, float);
	
	Vec3 operator + ();
	Vec3 operator - ();
	
	float& operator [] (int);
};

Vec3 operator + (Vec3, Vec3);
Vec3 operator - (Vec3, Vec3);
Vec3 operator * (Vec3, Vec3);
Vec3 operator / (Vec3, Vec3);

Vec3 operator * (Vec3, float);
Vec3 operator * (float, Vec3);
Vec3 operator / (Vec3, float);

float dot(Vec3, Vec3);
Vec3 cross(Vec3, Vec3);
float magnitude(Vec3);
Vec3 normalise(Vec3);

Vec3 reflect(Vec3, Vec3);
Vec3 refract(Vec3, Vec3, float);

std::ostream& operator << (std::ostream&, Vec3);

}