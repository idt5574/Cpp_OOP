#include <iostream>

class Distance {
	enum type_assign {
		isum_operation,
		isub_operation,
		imult_operation,
		idiv_operation
	};

	int _assign_operation(int right, type_assign type)
	{
		switch(type){
			case isum_operation:
				dist += right;
				break;
			case isub_operation:
				dist -= right;
			      	break;
			case imult_operation:
				dist *= right;
				break;
			case idiv_operation:
				dist /= right;
				break;	
		};

		return dist;
	}

	int dist {0};

public:
	Distance(int d) : dist(d)
	{}

	operator int() const
	{
		return dist;	
	}

	int operator+=(int right)
	{
		return _assign_operation(right, isum_operation);	
	}

	int operator -=(int right)
	{
		return _assign_operation(right, isub_operation);
	}	

	int operator *=(int right)
	{
		return _assign_operation(right, imult_operation);
	}

	int operator /=(int right)
	{
		return _assign_operation(right, idiv_operation);
	}

};
