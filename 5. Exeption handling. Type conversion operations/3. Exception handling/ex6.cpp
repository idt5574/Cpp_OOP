#include <iostream>
#include <string>

class Validator
{
protected:
    std::string msg_ex;

public:

    Validator(const std::string msg) : msg_ex(msg) {}

    virtual bool is_valid(int x, bool exception = true) const = 0;
    virtual ~Validator() {}
};

class ValidatorRange : public Validator
{
    int min_value {0}, max_value {0};

public: 

    ValidatorRange(const std::string msg, int min_value, int max_value)
    : Validator(msg), min_value(min_value), max_value(max_value) { }

    virtual bool is_valid(int x, bool exception = true) const override
    {
        bool res = (x >= min_value && x <= max_value);

        if(!exception)
            return res;

        if(!res)
            throw msg_ex;

        return true;
    }
};

int main()
{
    ValidatorRange vr {"Value is outside the range [0; 15]", 0, 15};

    int x;
    std::cin >> x;

    try
    {
        vr.is_valid(x);
    }
    catch(std::string e)
    {
        std::cout << e << '\n';
    }

    // __ASSERT_TESTS__

    return 0;
}