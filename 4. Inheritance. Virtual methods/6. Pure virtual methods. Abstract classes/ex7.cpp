#include <iostream>
#include <cmath>

class Vector3D
{
    int x {0}, y {0}, z {0};

    class Item
    {
        unsigned short index {0};
        Vector3D* current {nullptr};

    public:

        Item(Vector3D* object, unsigned short index)
        : current(object), index(index) {}

        operator int() const
        {
            switch (index)
            {
            case 0: return current->x;

            case 1: return current->y;

            case 2: return current->z;
            }
        }

        void operator=(int right)
        {
            switch (index)
            {
            case 0: current->x = right;
                return;

            case 1: current->y = right;
                return;

            case 2: current->z = right;
                return;
            } 
        }
    };

public:

    Vector3D(int a = 0, int b = 0, int c = 0)
    : x(a), y(b), z(c) {}

    void set_data(int a, int b, int c)
    { x = a; y = b; z = c; }

    Item operator[] (unsigned short index)
    { return Item(this, index); }

    operator double() const
    { return sqrt(x * x + y * y + z * z); }
    
};