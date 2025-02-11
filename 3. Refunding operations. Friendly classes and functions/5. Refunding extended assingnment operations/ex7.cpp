#include <iostream>
#include <string>

struct BankAccount {
	std::string fio;
	long volume {0};

	BankAccount() = default;
	BankAccount(const std::string& fio, long vol) : fio(fio), volume(vol)
	{}

	const BankAccount& operator+=(long other)
	{
		volume += other;
		return *this;
	}

	const BankAccount& operator-=(long other)
	{
		volume -= other;
		return *this;
	}

	const BankAccount& operator*=(long other)
	{
		volume *= other;
		return *this;
	}

	const BankAccount& operator/=(long other)
	{
		if(other != 0) volume /= other;
		return *this;
	}

	const BankAccount& operator%=(long other)
	{
		if(other != 0) volume %= other;
		return *this;
	}
	
};

class Bank {
	enum { max_accounts = 100 };
	BankAccount* acs {nullptr};
	size_t count {0};

public:
	Bank()
	{
		acs = new BankAccount[max_accounts];
	}

	Bank(BankAccount* lst, size_t size) : count ((size > max_accounts) ? max_accounts : size)
	{
		acs = new BankAccount[max_accounts];

		if(lst)
			for(int i = 0; i < count; i++)
				acs[i] = lst[i];
	}

	const BankAccount* get_accounts() const
	{ return acs; }

	size_t get_count() const
	{ return count; }

	const Bank& operator=(const Bank& other)
	{
		if(this == &other)
			return *this;

		if(acs != nullptr)
			delete[] acs;

		count = other.count;
		acs = new BankAccount[max_accounts];

		for(int i = 0; i < count; i++)
			acs[i] = other.acs[i];

		return *this;
	}
		
	
	Bank operator+(const BankAccount& right) const	 
	{
		Bank new_bank;
		new_bank = *this;
		new_bank += right;

		return new_bank;
	}

	const Bank& operator+=(const BankAccount& right)
	{
		if(count == max_accounts)
			return *this;

		acs[count++] = right;
		return *this;
	}

	~Bank() { delete[] acs; }
};

int main()
{
	Bank my_bank;
	my_bank += {"А. Дзюба", 43056};
	my_bank += {"П. Гагарина", 1335395};
	my_bank += {"О. Бузова", 0};
	my_bank += {"Тимати", -546};

	// __ASSERT_TESTS__

	return 0;
}
