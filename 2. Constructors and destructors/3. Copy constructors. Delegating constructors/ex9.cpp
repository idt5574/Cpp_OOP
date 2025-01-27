#include <iostream>

class Vector3D
{
    int x, y, z;

public:

    Vector3D(int x=0, int y=0, int z=0) : x(x), y(y), z(z)
        { }

    void set_coords(int a, int b, int c)
    { 
        if(a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100) return;

        x = a; 
        y = b; 
        z = c; 
    }
    
    void get_coords(int& x, int& y, int& z)
    { 
        x = this->x; 
        y = this->y; 
        z = this->z; 
    }
    
};

int main()
{
    Vector3D *ptr_v1 = new Vector3D{10, -5, 7},
        *ptr_v2 = new Vector3D{0, 12, -56};


    // __ASSERT_TESTS__

    delete ptr_v1,
    delete ptr_v2;

    return 0;
}