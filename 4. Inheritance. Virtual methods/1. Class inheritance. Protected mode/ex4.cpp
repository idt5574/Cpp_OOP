#include <iostream>

class ValidatorInteger
{
    int err_no {0}; 

public:
    ValidatorInteger() = default;

    int get_errno() const { return err_no; }
    bool is_valid(int x) const { return true; }
};

class ValidatorRange : public ValidatorInteger
{
    int min_value {0}, max_value {0};

public:

    ValidatorRange(int min, int max)
    : min_value(min), max_value(max) {}

    bool is_valid(int x) const
    { return (x >= min_value && x <= max_value); }
};

class ValidatorPositive : public ValidatorInteger
{
public:
    ValidatorPositive() = default;

    bool is_valid(int x) const 
    { return x > -1; }
};

int main()
{
    ValidatorRange vr {-5, 7};
    ValidatorPositive v_positive;

    int x;
    std::cin >> x;

    std::cout << vr.is_valid(x) << ' ' << v_positive.is_valid(x) << std::endl;

    // __ASSERT_TESTS__

    return 0;
}