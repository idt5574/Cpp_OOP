#include <iostream>
#include <cstring>

class Point {
    int x, y;
public:
    Point() : x(0), y(0)
        {   }

    Point(const char* str)
    {
        if(sscanf(str, "%d", &x) != 1)
            x = 0;

        if(sscanf(str, "%*s %d", &y) != 1)
            y = 0;
    }

    int get_x() { return x; }
    int get_y() { return y; }
};

int main()
{
    Point p1 = "10 5"; // x=10, y=5
    Point p2 = "-8.7 2.3"; // x=-8, y=2
    Point p3 = "14.2 -5.8 point data"; // x=14, y=-5
    Point p_1 = "ab8 2.3"; // x=0, y=2
    Point p_2 = "ab8 2cd"; // x=0, y=2 (cd отбрасывается)


    return 0;
}