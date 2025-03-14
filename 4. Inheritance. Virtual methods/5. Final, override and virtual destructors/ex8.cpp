#include <iostream>

int clamp(int value, int left_border, int right_border)
{
	if(value < left_border) {value = left_border; return value; }
	if(value > right_border) {value = right_border; return value; }
	return value;
}

class LimitLength
{
	enum type_assign {
		isum_operation,
		isub_operation,
		imult_operation,
		idiv_operation
	};

	enum {min_length = -10, max_length = 10};
	int length {0};

	inline const LimitLength& _assign_operation(int right, type_assign type)
	{
		switch(type)
		{
			case isum_operation:
				length += right;
				break;
			case isub_operation:
				length -= right;
				break;
			case imult_operation:
				length *= right;
				break;
			case idiv_operation:
				length /= right == 0 ? 1 : right;
				break;
		};

		clamp(length, min_length, max_length);
		return *this;
	}

public:


	LimitLength(int len = 0) : length(clamp(len, min_length, max_length))
	{}

	int get_length() const { return length; }

	const LimitLength& operator += (int right)
	{ return _assign_operation(right, isum_operation); }
	const LimitLength& operator -= (int right)
	{ return _assign_operation(right, isub_operation); }
	const LimitLength& operator *= (int right)
	{ return _assign_operation(right, imult_operation); }
	const LimitLength& operator /= (int right)
	{ return _assign_operation(right, idiv_operation); }

	const LimitLength& operator++()
	{ return _assign_operation(1, isum_operation); }
	LimitLength operator++(int)
	{ 
		LimitLength temp = *this;
		_assign_operation(1, isum_operation); 
		return temp;
	}

	const LimitLength& operator--()
	{ return _assign_operation(1, isub_operation); }
	LimitLength operator--(int)
	{
		LimitLength temp = *this;
		_assign_operation(1, isub_operation);
		return temp;
	}

	operator int() const
	{ return length; }
};

int main()
{
	LimitLength lm1 = -5;
	int a = lm1++;
	int b = ++lm1;
	int c = lm1--;
	int d = --lm1;
	int res_1 = lm1 += 5;
	int res_2 = lm1 -= 15;
	int res_3 = lm1 *= 2;
	int res_4 = lm1 /= 3;

	printf("%d %d %d %d\n%d %d %d %d\n", a, b, c, d, res_1, res_2, res_3, res_4);

	return 0;
}
