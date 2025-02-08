#include <iostream>
#include <cmath>

class Vector3D {
	enum {
		value_error=5437983
	};

	int x {0}, y {0}, z {0};

public:
	Vector3D(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c)
		{ }

	void set_data(int a, int b, int c) { x = a; y = b; z = c; }

	int& operator[] (int index)
	{
		if(index == 0) return x;
		if(index == 1) return y;
		return z;
	}

	operator double() const
	{
		return sqrt(x * x + y * y + z * z); 
	}
	
};
