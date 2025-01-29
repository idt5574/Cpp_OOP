#include <iostream>

class Figure
{
    int x0 {0}, y0 {0}, x1{0}, y1 {0};

public:
    Figure() = default;
    Figure(const Figure& other) = delete;
    const Figure& operator=(const Figure& other) = delete;
    Figure(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1)
        { }

    void get_data(int& x0, int& y0, int& x1, int& y1)
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
};

int main(void)
{
    Figure fig(-4, 2, 11, 7);

    /*  
        Figure f, f2; // allow
        Figure f_cp(f); // disallow
        f = f2; // disallow
    */

    // __ASSERT_TESTS__ 

    return 0;
}