#include <iostream>

class Validator
{
public:
    
    Validator() = default;

    virtual bool is_valid(int x) const
    { return true; }

};

class PositiveValidator : public Validator
{
public:

    PositiveValidator() = default;

    bool is_valid(int x) const
    { return x >= 0; }

};

class RangeValidator : public Validator
{
    int left {0}, right {0};

public:

    RangeValidator(int left, int right)
    : left(left), right(right) {}

    bool is_valid(int x) const
    { return (x >= left && x <= right); }

};

int main()
{
    Validator* vs[3] {
        new PositiveValidator(),
        new RangeValidator(-5, 5),
        new RangeValidator(-15, 10)
    };

    int user_value;
    std::cin >> user_value;

    // __ASSERT_TESTS__

    for(int i = 0; i < 3; i++)
    {
        std::cout << vs[i]->is_valid(user_value) << ' ';
        delete vs[i];
    }

    std::cout << std::endl;

    return 0;
}