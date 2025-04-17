#include <iostream>
#include <string>

template <typename T>
class Validator
{
protected:
    std::string msg_ex;

public:
    Validator(const std::string& error) : msg_ex(error) {}

    virtual bool is_valid(T x, bool exception = true) const = 0;
    virtual ~Validator() {}
};

template <typename T>
class ValidatorRange : public Validator<T>
{
    T min_value {0}, max_value {0};

public:
    
    ValidatorRange(const std::string& error, T min_value, T max_value)
    : min_value(min_value), max_value(max_value), Validator<T>(error) {}

    bool is_valid(T x, bool exception = true) const override
    {
        bool res = x >= min_value && x <= max_value;

        if(exception && !res)
            throw Validator<T>::msg_ex;

        return res;
    }

    ~ValidatorRange() {}
};

int main()
{
    ValidatorRange vr {"Value is outside the range [-4.5; 2.5]", -4.5, 2.5};

    try
    {
        double x;
        std::cin >> x;

        vr.is_valid(x);
    }
    catch(const std::string& e)
    {
        std::cout << e << '\n';
    }
    
    // __ASSERT_TESTS__

    return 0;
}