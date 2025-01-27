#include <iostream>
#include <string>

class Complex
{
    short re, im;

public:

    Complex(short re=0, short im=0) : re(re), im(im)
        { }
    
    Complex(Complex& other) : re(abs(-other.re)), im(abs(-other.im))
        { }

    short get_real()
        { return re; }
    
    short get_imag()
        { return im; }

};

int main()
{
    Complex digit{-4, 7},
        res{digit};

    // __ASSERT_TESTS__

    return 0;
}