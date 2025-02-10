#include <iostream>

class BottleWater
{
	enum type_assign {
		isum_operation,
		isub_operation,
		imult_operation,
		idiv_operation
	};

	enum { max_volume = 640 };
	short volume {0};

	int _assign_operation(const BottleWater& right, type_assign type)
	{
		if((type == isum_operation && right.volume * volume > max_volume) || 
				(type == imult_operation && right.volume + volume > max_volume))
		{
			volume = max_volume;
			return volume;
		};
		
		if(type == isub_operation && volume - right.volume < 0)
		{
			volume = 0;
			return volume;
		}	

		switch(type)
		{
			case isum_operation:
				volume += right.volume;
				return volume;
			case isub_operation:
				volume -= right.volume;
				return volume;
			case imult_operation:
				volume *= right.volume;
				return volume;
			case idiv_operation:
				volume /= right.volume;
				return volume;	
		};
	}

public:
	BottleWater(short volume=0)
	{
		if(volume > max_volume)
		{
			this->volume = max_volume;
			return;
		}

		if(volume < 0)
		{
			this->volume = 0;
			return;	
		}

		this->volume = volume;
	}

	short get_volume() const { return volume; }

	int operator +(const BottleWater& right)
	{
		return volume + right.volume > max_volume ? max_volume : volume + right.volume;
	}

	int operator +=(const BottleWater& right)
	{ return _assign_operation(right, isum_operation); }
	int operator -=(const BottleWater& right)
	{ return _assign_operation(right, isub_operation); }
	int operator *=(const BottleWater& right)
	{ return _assign_operation(right, imult_operation); }
	int operator /=(const BottleWater& right)
	{ return _assign_operation(right, idiv_operation); }
};

int main()
{
	BottleWater bw1{40}, bw2{200};
	BottleWater res = bw1 + bw2;

	__ASSERT_TESTS__
		
	return 0;
}
