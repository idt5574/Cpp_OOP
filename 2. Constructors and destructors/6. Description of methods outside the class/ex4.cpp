#include <iostream>

class Clock
{
    unsigned tm {0};

public:

    Clock() = default;
    Clock(unsigned tm) : tm(tm)
        { }

    unsigned get_time();

};

unsigned Clock::get_time() 
    { return tm; }

int main()
{
    Clock *ptr_cl = new Clock(12643);

    unsigned res = ptr_cl->get_time();

    // __ASSERT_TESTS__

    delete ptr_cl;

    return 0;
}