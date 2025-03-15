#include <iostream>
#include <string>

class BankAccount
{
    std::string fio;
    long volume_rub {0};

public:

    BankAccount(const std::string& fio, long volume_rub = 0)
    : fio(fio), volume_rub(volume_rub) {}

    const std::string& get_fio() const
    { return fio; }

    long get_volume_rub() const
    { return volume_rub; }

    const BankAccount& operator=(long right)
    {
        volume_rub = right;
        return *this;
    }

    const BankAccount& operator+=(int right)
    {
        volume_rub += right;
        return *this;
    }

    const BankAccount& operator-=(int right)
    {
        volume_rub -= right;
        return *this;
    }

    const BankAccount& operator+=(const BankAccount& right)
    {
        volume_rub += right.volume_rub;
        return *this;
    }

    const BankAccount& operator-=(const BankAccount& right)
    {
        volume_rub -= right.volume_rub;
        return *this;
    }

};