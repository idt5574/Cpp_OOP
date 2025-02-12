#include <iostream>

class Clock
{
	unsigned tm {0};

public:

	Clock(unsigned tm=0) : tm(tm)
	{}

	unsigned get_time() const
	{ return tm; }

	operator int() const
	{ return tm; }

	const Clock& operator=(const Clock& other)
	{
		if(this == &other)
			return *this;

		tm = other.tm;
		return *this;
	}

	Clock operator +(const Clock& right) const
	{
		Clock temp = tm + right.tm;
		return temp;
	}

	const Clock& operator+=(const Clock& right)
	{ tm += right.tm; return *this; }
	const Clock& operator-=(const Clock& right)
	{ tm -= right.tm; return *this; }
	const Clock& operator*=(const Clock& right)
	{ tm *= right.tm; return *this; }
	const Clock& operator/=(const Clock& right)
	{ tm /= right.tm == 0 ? 1 : right.tm; return *this; }

	const Clock& operator++()
	{ tm++; return *this; }
	Clock operator++(int)
	{
		Clock temp = *this;
		tm++;
		return temp;
	}

	const Clock& operator--()
	{ tm--; return *this; }
	Clock operator--(int)
	{ 
		Clock temp = *this;
		tm--;
		return temp;
	}

};

int main()
{
	Clock clock_1{100}, clock_2{430},
	      res = clock_1 + clock_2;

	// __ASSERT_TESTS__
	return 0;	
}
