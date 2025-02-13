#include <iostream>

class LineDouble
{
	double x0 {0}, y0 {0}, x1 {0}, y1 {0};

public:
	
	LineDouble(double a=0, double b=0, double c=0, double d=0) : x0(a), y0(b), x1(c), y1(d)
	{}

	void set_coords(double a, double b, double c, double d)
	{ x0 = a; y0 = b; x1 = c; y1 = d; };

	void get_coords(double& a, double& b, double& c, double& d) const
	{ a = x0; b = y0; c = x1; d = y1; }

	const LineDouble& operator=(const LineDouble& other)
	{
		if(this == &other)
			return *this;

		x0 = other.x0; y0 = other.y0;
		x1 = other.x1; y1 = other.y1;

		return *this;
	}

	LineDouble operator+(const LineDouble& other) const
	{
		LineDouble new_line{x0 + other.x0, y0 + other.y0, x1 + other.x1, y1 + other.y1};
		return new_line;
	}
		
	const LineDouble& operator+=(const LineDouble& other)
	{
		x0 += other.x0;
		y0 += other.y0;
		x1 += other.x1;
		y1 += other.y1;

		return *this;
	}
	const LineDouble& operator-=(const LineDouble& other)
	{
		x0 -= other.x0;
		y0 -= other.y0;
		x1 -= other.x1;
		y1 -= other.y1;

		return *this;
	}	

	const LineDouble& operator+=(double other)
	{
		x0 += other;
		y0 += other;
		x1 += other;
		y1 += other;

		return *this;
	}
	const LineDouble& operator-=(double other)
	{
		x0 -= other;
		y0 -= other;
		x1 -= other;
		y1 -= other;

		return *this;
	}

	const LineDouble& operator++()
	{ x0 += 0.1; y0 += 0.1; x1 += 0.1; y1 += 0.1; return *this;}
	const LineDouble& operator--()
	{ x0 -= 0.1; y0 -= 0.1; x1 -= 0.1; y1 -= 0.1; return *this;}

	LineDouble operator++(int)
	{
		LineDouble temp(*this);
		++(*this);
		return temp;

	}
	LineDouble operator--(int)
	{
		LineDouble temp(*this);
		--(*this);
		return temp;
	}
};
