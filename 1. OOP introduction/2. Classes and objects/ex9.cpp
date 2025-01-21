#include <iostream>

using std::cin;
using std::cout;

class Clock {
    unsigned time_current;

public:
    void set_time(unsigned tm) { time_current = tm; }

    unsigned get_hours() { return time_current / 3600; }
    unsigned get_minutes() { return time_current / 60 % 60; }
    unsigned get_seconds() { return time_current % 60; }
};

int main() {
    Clock *ptr_cl = new Clock;

    unsigned tm;
    cin >> tm;

    ptr_cl->set_time(tm);

    printf("%02u:%02u:%02u\n", ptr_cl->get_hours(), ptr_cl->get_minutes(), ptr_cl->get_seconds());

    // __ASSERT_TESTS__

    delete ptr_cl;

    return 0;
}