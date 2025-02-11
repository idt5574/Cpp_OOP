#include <iostream>

class Line
{
	short x0 {0}, y0 {0}, x1 {0}, y1 {0};
	int color {0};

public:
	Line() = default;
	Line(short x0, short y0, short x1, short y1)
		: x0(x0), y0(y0), x1(x1), y1(y1)
	{}

	int get_color() { return color; }

	void get_coords(short& x0, short& y0, short& x1, short& y1)
	{ x0 = this->x0; y0 = this->y0; x1 = this->x1; y1 = this->y1; }

	void set_coords(short x0, short y0, short x1, short y1)
	{ this->x0 = x0; this->y0 = y0; this->x1 = x1; this->y1 = y1; }

	void set_color(int color)
	{ this->color = color; }

	const Line& operator=(const Line& other)
	{
		x0 = other.x0; y0 = other.y0; x1 = other.x1; y1 = other.y1;
		return *this;
	}

	Line operator+(const Line& other)
	{
		return Line(x0 + other.x0, y0 + other.y0, x1 + other.x1, y1 + other.y1);
	}
	
	Line& operator+=(const Line& other)
	{ 
		x0 += other.x0; y0 += other.y0; x1 += other.x1; y1 += other.y1;
		return *this;
	}

	Line& operator-=(const Line& other)
	{ 
		x0 -= other.x0; y0 -= other.y0; x1 -= other.x1; y1 -= other.y1;
		return *this;
	}
	
	Line& operator*=(const Line& other)
	{
		x0 *= other.x0; y0 *= other.y0; x1 *= other.x1; y1 *= other.y1;
		return *this;
	}

};


