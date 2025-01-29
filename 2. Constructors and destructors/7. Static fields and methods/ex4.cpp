#include <iostream>

class Point
{
    static int MIN_COORD, MAX_COORD;

    int x{0}, y{0};

    bool check_coord(int);

public:
    
    Point() = default;
    
    Point(int x, int y)
    { 
        if(check_coord(x) && check_coord(y))
        {
            this->x = x;
            this->y = y;
        } else Point();
    }

    static void set_bounds(int, int);
    static void get_bounds(int&, int&);

    void set_coords(int, int);
    int get_x() { return x; }
    int get_y() { return y; }

};

bool Point::check_coord(int coord)
    { return MIN_COORD <= coord and MAX_COORD >= coord; }

void Point::set_bounds(int left, int right)
    { MIN_COORD = left; MAX_COORD = right; }

void Point::get_bounds(int& left, int& right)
    { left = MIN_COORD; right = MAX_COORD; }

void Point::set_coords(int x, int y)
{
    if(!check_coord(x) || !check_coord(y)) return;

    this->x = x;
    this->y = y;
}

int Point::MIN_COORD = 0;
int Point::MAX_COORD = 10;

int main()
{
    Point::set_bounds(-100, 100);
    Point pt(-5, 7);

    // __ASSERT_TESTS__

    return 0;
}