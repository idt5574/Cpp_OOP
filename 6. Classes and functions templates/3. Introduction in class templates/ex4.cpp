#include <iostream>
#include <string>

class LengthValueError : public std::exception
{
    std::string msg;

public:

    LengthValueError(const std::string& error) : msg(error) {}

    const char * what() const noexcept override { return msg.c_str(); }

    ~LengthValueError() {}

};

template <typename T = short>
class Triangle
{
    T a{0}, b{0}, c{0};

public:

    Triangle();
    Triangle(T, T, T);

    void get_abc(T&, T&, T&) noexcept;
    void set_abc(T, T, T);

};

template <typename T>
Triangle<T>::Triangle() = default;

template<typename T>
Triangle<T>::Triangle(T a, T b, T c) 
{
    if(a < 0 || b < 0 || c < 0)
        throw LengthValueError("Length must be a positive number.");

    this->a = a; this->b = b; this->c = c;
}

template <typename T>
void Triangle<T>::get_abc(T& a, T& b, T& c) noexcept
{
    a = this->a; b = this->b; c = this->c;
}

template <typename T>
void Triangle<T>::set_abc(T a, T b, T c)
{
    if(a < 0 || b < 0 || c < 0)
        throw LengthValueError("Length must be a positive number.");

    this->a = a; this->b = b; this->c = c;
}

int main()
{
    try
    {
        Triangle tr {7, -4, 10};
    }
    catch(const LengthValueError& e)
    {
        std::cout << e.what() << '\n';
    }

    // __ASSERT_TESTS__

    return 0;
}
