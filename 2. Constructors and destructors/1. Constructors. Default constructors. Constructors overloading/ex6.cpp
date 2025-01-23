#include <iostream>

class Wallet 
{
    long volume;

public:
    Wallet(long v=0) : volume(v)
        {}

    void set_volume(long volume)
        { this->volume = volume; }
    
    long get_volume()
        { return volume; }
};

int main()
{
    Wallet wt1(1000), wt2;

    // __ASSERT_TESTS__
    return 0;
}