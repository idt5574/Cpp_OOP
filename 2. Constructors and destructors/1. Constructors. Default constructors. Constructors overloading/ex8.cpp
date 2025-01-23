#include <iostream>

struct Point
{
    short x, y;
};

class Line
{
    short x0, y0, x1, y1;

public:
    Line(int a=0, int b=0, int c=0, int d=0) : x0(a), y0(b), x1(c), y1(d)
        {}

    Line(Point sp, Point ep) : x0(sp.x), y0(sp.y), x1(ep.x), y1(ep.y)
        {}

    void set_coords(short a, short b, short c, short d)
        { x0 = a; y0 = b; x1 = c; y1 = d; }
    
    void set_coords(Point sp, Point ep)
    {
        x0 = sp.x;
        y0 = sp.y;
        x1 = ep.x;
        y1 = ep.y;
    }

    Point get_start()
        { return (Point){x0, y0}; }
    
    Point get_end()
        { return (Point){x1, y1}; }
    
};

int main()
{
    Point sp, ep;
    short a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cin >> sp.x >> sp.y >> ep.x >> ep.y;

    Line *ptr_ln1 = new Line(a, b, c, d),
        *ptr_ln2 = new Line(sp, ep);
    
    printf("%d %d %d %d %d %d %d %d\n", 
            ptr_ln1->get_start().x, ptr_ln1->get_start().y, ptr_ln1->get_end().x, ptr_ln1->get_end().y,
            ptr_ln2->get_start().x, ptr_ln2->get_start().y, ptr_ln2->get_end().x, ptr_ln2->get_end().y);

    // __ASSERT_TESTS__ 

    delete ptr_ln1;
    delete ptr_ln2;

    return 0;
}