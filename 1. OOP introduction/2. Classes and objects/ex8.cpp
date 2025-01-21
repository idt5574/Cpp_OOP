#include <iostream>

class Table {
    unsigned width, height, depth;

public:
    void set_dims(unsigned width, unsigned height, unsigned depth) {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }

    unsigned get_width() { return width; }
    unsigned get_height() { return height; }
    unsigned get_depth() { return depth; }

};

int main()
{
    Table t1, t2, t3;

    t1.set_dims(10, 10, 5);
    t2.set_dims(7, 20, 7);
    t3.set_dims(12, 40, 6);

    // __ASSERT_TESTS__
    return 0;
}   