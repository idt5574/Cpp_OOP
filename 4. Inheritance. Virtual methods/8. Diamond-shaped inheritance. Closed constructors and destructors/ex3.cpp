#include <iostream>

class TimeValue {
protected:
    unsigned tm {0}; // текущее время
public:
    int get_time() const { return tm; }
    virtual ~TimeValue() { }
};

class ClockOperators : virtual public TimeValue {
public:
    ClockOperators(unsigned tm) { this->tm = tm; }
    unsigned operator+(const ClockOperators& right)
    {
        return this->tm + right.tm;
    }
    virtual ~ClockOperators() { }
};

class ClockPrint : virtual public TimeValue {
public:
    void print()
    {
        unsigned h = tm / 3600;
        unsigned m = (tm - h * 3600) / 60;
        unsigned s = (tm - h * 3600 - m * 60);

        printf("%02u:%02u:%02u\n", h, m, s);
    }
    virtual ~ClockPrint() { }
};

class Clock : public ClockOperators, public ClockPrint
{
public:
    Clock() : ClockOperators(0) {}
    Clock(unsigned tm) : ClockOperators(tm) {}
};

int main(void)
{
    Clock cl_1(15334), cl_2(43654);
    Clock res = cl_1 + cl_2;

    std::cout << res.get_time() << std::endl;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}