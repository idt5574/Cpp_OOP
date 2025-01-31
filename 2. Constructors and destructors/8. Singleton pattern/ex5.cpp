#include <iostream>

class DeskTop {
    int width {0}, height {0};
    static DeskTop* obj;

    DeskTop() = default;
    DeskTop(int width, int height) : width(width), height(height)
        {} 

public:

    DeskTop(const DeskTop&) = delete;

    static DeskTop* get_instance(int width, int height)
    {
        if(obj == nullptr)
            obj = new DeskTop(width, height);

        return obj;
    }

    int get_width() { return  width; }
    int get_height() { return height; }

    ~DeskTop()
        { obj = nullptr; }

};

DeskTop* DeskTop::obj = nullptr;

int main()
{   
    DeskTop* ptr_desk = DeskTop::get_instance(500, 200); // width = 200, height = 50

    // __ASSERT_TESTS__

    return 0;
}