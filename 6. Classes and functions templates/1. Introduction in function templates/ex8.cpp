#include <iostream>

enum ar_operation {
    ar_sum = 1,
    ar_sub,
    ar_mul
};

class Complex
{
    int re {0}, im {0};

public:

    Complex(int re = 0, int im = 0) : re(re), im(im) {}

    int real() const
    {
        return re;
    }

    int imag() const
    {
        return im;
    }

    void set_value(int real, int imag)
    {
        re = real;
        im = imag;
    }

    const Complex& operator = (const Complex& other)
    {
        if(this == &other) 
            return *this;

        re = other.re;
        im = other.im;

        return *this;
    }

    Complex operator + (const Complex& other)
    {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator - (const Complex& other)
    {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator * (const Complex& other)
    {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

};

template <typename T>
T calc_data(T a, T b, ar_operation type = ar_sum)
{
    switch (type)
    {
    case ar_sum:
        return a + b;
    
    case ar_sub:
        return a - b;

    case ar_mul:
        return a * b;
    }
}

int main()
{
    Complex cmp_1(-5, 23), cmp_2(14, 7),
        res_1 = calc_data(cmp_1, cmp_2, ar_sub);

    double res_2 = calc_data(0.5, 10.4, ar_sum);

    int res_3 = calc_data(5, -11, ar_mul); 

    // __ASSERT_TESTS__

    return 0;
}