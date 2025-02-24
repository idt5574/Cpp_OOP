#include <iostream>

class SquareValue
{
    unsigned value {0};

public:
    
    SquareValue() = default;
    SquareValue(int val) : value(val * val) {}

    operator unsigned()
    {
        return value;
    }

    const SquareValue& operator=(const SquareValue& other)
    { 
        if(this == &other) return *this;
        value = other.value; 
        return *this;
    }
};

int main()
{
    SquareValue obj {9};

    SquareValue& lnk_sq {obj};
    SquareValue&& lnk_r_sq (std::move(obj));

    // __ASSERT_TESTS__

    return 0;
}