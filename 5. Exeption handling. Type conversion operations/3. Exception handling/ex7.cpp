#include <iostream>

class Wallet
{
    enum { wallet_limit = 1000000 };
    long volume {0};

    bool validate_volume(long new_vol)
    {
        if(new_vol > wallet_limit || new_vol < 0)
            throw "Value is out of bounds.";

        return true;
    }

public:

    Wallet(long volume = 0)
    {
        validate_volume(volume);
        this->volume = volume;
    }

    long get_volume()
    { return volume; }

    const Wallet& operator = (const Wallet& other)
    {
        if(this == &other)
            return other;
        
        this->volume = other.volume;

        return *this;
    }

    friend Wallet operator + (const Wallet& left, const Wallet& right);
    Wallet operator +=(const Wallet& right)
    { 
        validate_volume(this->volume + right.volume);
        this->volume += right.volume;

        return *this;
    }

    Wallet operator -=(const Wallet& right)
    { 
        validate_volume(this->volume - right.volume);
        this->volume -= right.volume;

        return *this;
    }

};

Wallet operator + (const Wallet& left, const Wallet& right)
{
    Wallet new_wallet (left.volume + right.volume);
    return new_wallet;
}

int main()
{
    try
    {
        Wallet wl = 500;
    }
    catch(const char* e)
    {
        std::cout << e << '\n';
    }
    
    // __ASSERT_TESTS__

    return 0;
}