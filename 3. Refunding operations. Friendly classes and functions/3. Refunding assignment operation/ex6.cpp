#include <iostream>
#include <string>

class BankAccount
{
    std::string fio;
    long volume_rub {0};

public:

    BankAccount(const char* str, long volume_rub=0) : fio(str), volume_rub{volume_rub}
        { } 

    const std::string& get_fio() const { return fio; }
    long get_volume_rub() const { return volume_rub; }

    const BankAccount& operator =(const long volume_rub)
    {
        this->volume_rub = volume_rub;

        return *this;
    }

};

int main()
{

    BankAccount a1("Balakirev"); // fio = "Balakirev"; volume_rub = 0
    BankAccount a2("Pushkin", 10000); // fio = "Pushkin"; volume_rub = 10000

    a1 = 512000; // volume_rub = 512000 (поле fio не меняется)


    return 0;
}