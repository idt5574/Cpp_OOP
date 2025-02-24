#include <iostream>

class ValueDouble
{
    double value {0.0};

public:

    ValueDouble() = default;
    ValueDouble(double value) : value(value)
    {}

    ValueDouble(const ValueDouble& other) : value(other.value)
    {}

    double get_value() const { return value; }

    friend ValueDouble operator+(const ValueDouble&, const ValueDouble&);
};

ValueDouble operator+(const ValueDouble& left, const ValueDouble& right)
{
    return ValueDouble(left.value + right.value);
}

int main()
{
    ValueDouble obj {8.7};
    ValueDouble& lnk_vd = obj;
    ValueDouble&& lnk_r_vd = std::move(obj);

    // __ASSERT_TESTS__

    return 0;
}