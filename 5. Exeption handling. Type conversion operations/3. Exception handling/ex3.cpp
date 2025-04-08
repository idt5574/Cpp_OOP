#include <iostream>

class Point
{
    enum { min_coord = -10, max_coord = 10 };
    int x{0}, y{0};

public:

    Point(int x = 0, int y = 0)
    {
        if(x < min_coord || x > max_coord || y < min_coord || y > max_coord)
            throw "Incorrect coordinate values.";
    
        this->x = x;
        this->y = y;
    }

};

int main()
{
    try
    {
        Point point {11, -5};
    }
    catch(const char * e)
    {
        std::cout << e << std::endl;
    }
    
    // __ASSERT_TESTS__

    return 0;
}