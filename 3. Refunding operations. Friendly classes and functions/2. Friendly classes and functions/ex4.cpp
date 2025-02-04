#include <iostream>

class ColorRGB {
    enum { max_color = 255 };

    unsigned char r{0}, g{0}, b{0};

public:

    ColorRGB(unsigned char red=0, unsigned char green=0, unsigned char blue=0) : r(red), g(green), b(blue)
        { }

    unsigned get_color() { return r + g * 256 + b * 65536; }

    friend ColorRGB operator +(const ColorRGB& left, const ColorRGB& right);

};

ColorRGB operator +(const ColorRGB& left, const ColorRGB& right)
{
    ColorRGB new_color{
        (int)left.r + (int)right.r > ColorRGB::max_color ? (unsigned char)ColorRGB::max_color : left.r + right.r,
        (int)left.g + (int)right.g > ColorRGB::max_color ? (unsigned char)ColorRGB::max_color : left.g + right.g,
        (int)left.b + (int)right.b > ColorRGB::max_color ? (unsigned char)ColorRGB::max_color : left.b + right.b
    };

    return new_color;
}

int main()
{
    ColorRGB rgb;
    ColorRGB rgb_w(255, 102, 0); // r = 255, g = 102, b = 0

    ColorRGB clr_1(100, 100, 100), clr_2(255, 0, 80);
    ColorRGB res = clr_1 + clr_2; // r = 255, g = 100, b = 180

    return 0;
}