#include <iostream>

struct Point
{
    short x, y;
};

class PolyLine
{
    enum { max_coords = 10 };
    Point coords[max_coords];
    int total {0};

public:
    PolyLine() : total(0)
        {}
    
    PolyLine(const Point* ar, int size_ar)
    {
       set_coords(ar, size_ar); 
    }

    void set_coords(const Point* ar, int size)
    {
        total = 0;

        for(int i = 0; i < size && i < max_coords; i++)
        {
            coords[i].x = ar[i].x;
            coords[i].y = ar[i].y;
            total++;
        }
    }

    void append_coord(Point pt)
        {
            if(total == max_coords) return;

            coords[total].x = pt.x;
            coords[total++].y = pt.y;
        }
    
    const Point* get_coords()
        { return coords; }

    int get_total()
        { return total; }

};

int main(void)
{
    Point coords[20];
    for(int i = 0;i < 20; ++i) {
        coords[i].x = i+1;
        coords[i].y = i+2;
    }

    PolyLine poly(coords, sizeof(coords) / sizeof(Point)),
        pl;
    
    pl.append_coord(coords[sizeof(coords) / sizeof(Point) - 1]);

    // __ASSERT_TESTS__ 

    return 0;
}