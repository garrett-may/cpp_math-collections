#pragma once

#include <math.h>
#include <assert.h>
#include <iostream>
#include "vec3.h"

namespace mth
{
		
class Mat4
{
private:
	float m[4][4];
	
public:
	Mat4();
	Mat4(std::initializer_list<std::initializer_list<float>>);
	Mat4(float);
	
	static const Mat4 IDENTITY;
	
	Mat4 operator + ();
	Mat4 operator - ();
	
	float& operator () (int, int);	
	const float& operator () (int, int) const;	
};

Mat4 operator + (const Mat4&, const Mat4&);
Mat4 operator - (const Mat4&, const Mat4&);
Mat4 operator * (const Mat4&, const Mat4&);

Vec3 transform(Vec3&, const Mat4&);
Vec3 rotate(Vec3&, const Mat4&);

std::ostream& operator << (std::ostream&, Mat4);

}