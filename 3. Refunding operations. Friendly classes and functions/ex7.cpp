#include <iostream>

int min(int a, int b)
    { return a > b ? b : a; }

int max(int a, int b)
    { return a > b ? a : b; }

class Rectangle {
    int x0{0}, y0{0}, x1{1}, y1{1};

public:

    Rectangle() = default;
    Rectangle(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1)
        { }

    void get_coords(int &x0, int &y0, int &x1, int &y1) const
        { x0 = this->x0; y0 = this->y0; x1 = this->x1; y1 = this->y1; }

    void set_coords(int x0, int y0, int x1, int y1)
        { this->x0 = x0; this->y0 = y0; this->x1 = x1; this->y1 = y1; }

    Rectangle operator +(const Rectangle& right) const
    {
        return Rectangle(min(x0, right.x0), min(y0, right.y0), max(x1, right.x1), max(y1, right.y1));
    }
};

int main()
{
    Rectangle rect_1{-5, 0, 10, 12},
        rect_2{1, -2, 7, 14},
        res = rect_1 + rect_2;

    // __ASSERT_TESTS__

    return 0;
}