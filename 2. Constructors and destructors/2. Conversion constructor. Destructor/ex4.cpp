#include <iostream>

class Vector3D {
    int x, y, z;
public:
    Vector3D() : x(0), y(0), z(0)
        {   }

    Vector3D(const char* str)
    {
        if(sscanf(str, "%d", &x) != 1)
            x = 0;

        if(sscanf(str, "%*s %d", &y) != 1)
            y = 0;

        if(sscanf(str, "%*s %*s %d", &z) != 1)
            z = 0;
    }

    Vector3D(const int* ar)
    {
        x = ar[0];
        y = ar[1];
        z = ar[2];
    }
    void get_coords(int& a, int& b, int& c) 
        { a = x; b = y; c = z; }
};

int main()
{
    Vector3D v1 = "1 2 -5"; // x=1, y=2, z=-5
    Vector3D v2 = "1.5 2.2 -5.7"; // x=1, y=2, z=-5
    Vector3D v3 = "1.5 2.2 -5.7 data"; // x=1, y=2, z=-5

    int coords_1[] = {2, 4, 7}, coords_2[] = {5, 3, 1, 0, 20};
    Vector3D v4 = coords_1; // x=2, y=4, z=7
    Vector3D v5 = coords_2; // x=5, y=3, z=1

    return 0;
}