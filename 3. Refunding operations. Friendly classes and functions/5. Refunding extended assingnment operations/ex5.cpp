#include <iostream>
#include <string>

class BankAccount
{
	enum type_assign {
		isum_operation,
		isub_operation
	};

	std::string fio{"dflt_fio"};
	long volume_rub {0};

	long _assign_operation(long right, type_assign type)
	{
		switch(type){
			case isum_operation:
				volume_rub += right;
				break;
			case isub_operation:
				volume_rub -= right;
				break;
		};

		return volume_rub;
	}
public:
	
	BankAccount(long volume) : volume_rub(volume)
	{ }

	BankAccount(const char* fio, long volume_rub=0) : fio(fio), volume_rub(volume_rub)
	{} 

	const std::string& get_fio()
	{ return fio; }

	long get_volume_rub()
	{ return volume_rub; }

	const BankAccount& operator=(const BankAccount& other)
	{
		if(this == &other)
			return other;

		this->volume_rub = other.volume_rub;

		return *this;	
	}

	long operator+=(const BankAccount& right)
	{
		return _assign_operation(right.volume_rub, isum_operation);
	}

	long operator-=(const BankAccount& right)
	{
		return _assign_operation(right.volume_rub, isub_operation);
	}
};
