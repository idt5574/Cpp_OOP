#include <iostream>

class AbsoluteValue 
{
    unsigned long value {0};

public:

    AbsoluteValue() = default;

    AbsoluteValue(long value)
    {
        if(value < 0)
            this->value = -value;
        else
            this->value = value;
    }

    const AbsoluteValue& operator =(const AbsoluteValue& other)
    {
        value = other.value;

        return *this;
    }
};

int main(void)
{
    AbsoluteValue *ptr_abv = new AbsoluteValue();
    *ptr_abv = -512;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_abv;

    return 0;
}