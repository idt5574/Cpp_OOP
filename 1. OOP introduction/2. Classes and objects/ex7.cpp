#include <iostream>

class Vector3D {
    int x, y, z;

public:
    void set_coords(int a, int b, int c) {
        if(!((-100 <= a <= 100) || (-100 <= b <= 100) || (-100 <= c <= 100))) return;

        x = a;
        y = b;
        z = c;
    }

    void get_coords(int& x, int& y, int& z) {
        x = this->x;
        y = this->y;
        z = this->z;
    }
};

int main() {
    Vector3D *ptr_v1 = new Vector3D,
                *ptr_v2 = new Vector3D;

    ptr_v1->set_coords(10, -5, 7);
    ptr_v2->set_coords(0, 12, -56);

    // __ASSERT_TESTS__

    delete ptr_v1;
    delete ptr_v2;

    return 0;
}