#include "mat4.h"

namespace mth
{
	
Mat4::Mat4()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			m[i][j] = 0.0f;
		}
	}
}

Mat4::Mat4(std::initializer_list<std::initializer_list<float>> rows)
{
	assert(rows.size() == 4);
	int i = 0;
	for(std::initializer_list<float> row : rows)
	{
		assert(row.size() == 4);
		std::copy(row.begin(), row.end(), this->m[i++]);
	}
}

Mat4::Mat4(float value)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			m[i][j] = value;
		}
	}
}

const Mat4 Mat4::IDENTITY = {
	{1.0f, 0.0f, 0.0f, 0.0f},
	{0.0f, 1.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 1.0f, 0.0f},
	{0.0f, 0.0f, 0.0f, 1.0f}
};

Mat4 Mat4::operator + ()
{
	Mat4 r;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			r(i, j) = this->m[i][j];
		}
	}
	return r;
}

Mat4 Mat4::operator - ()
{
	Mat4 r;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			r(i, j) = -this->m[i][j];
		}
	}
	return r;
}

float& Mat4::operator () (int i, int j)
{
	return this->m[i][j];
}

const float& Mat4::operator () (int i, int j) const
{
	return this->m[i][j];
}

Mat4 operator + (const Mat4& a, const Mat4& b)
{
	Mat4 r;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			r(i, j) = a(i, j) + b(i, j);
		}
	}
	return r;
}


Mat4 operator - (const Mat4& a, const Mat4& b)
{
	Mat4 r;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			r(i, j) = a(i, j) - b(i, j);
		}
	}
	return r;
}


Mat4 operator * (const Mat4& a, const Mat4& b)
{
	Mat4 r;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				r(i, j) += a(i, k) + b(k, j);
			}			
		}
	}
	return r;
}

Vec3 transform(Vec3& v, const Mat4& m)
{
	return Vec3(
					m(0, 0) * v[0] + m(1, 0) * v[1] + m(2, 0) * v[2] + m(3, 0),
					m(0, 1) * v[0] + m(1, 1) * v[1] + m(2, 1) * v[2] + m(3, 1),
					m(0, 2) * v[0] + m(1, 2) * v[1] + m(2, 2) * v[2] + m(3, 2)
			   );
}

Vec3 rotate(Vec3& v, const Mat4& m)
{
	return Vec3(
					m(0, 0) * v[0] + m(1, 0) * v[1] + m(2, 0) * v[2],
					m(0, 1) * v[0] + m(1, 1) * v[1] + m(2, 1) * v[2],
					m(0, 2) * v[0] + m(1, 2) * v[1] + m(2, 2) * v[2]
			   );
}

std::ostream& operator << (std::ostream& os, Mat4 a)
{
	for(int i = 0; i < 3; i++)
	{
		os << "[";
		for(int j = 0; j < 3; j++)
		{
			os << a(i, j) << ",";
		}
		os << a(i, 3) << "]" << std::endl;
	}
	os << "[";
		for(int j = 0; j < 3; j++)
		{
			os << a(3, j) << ",";
		}
	os << a(3, 3) << "]";
	return os;
}

}