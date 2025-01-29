#include <iostream>

class Window {

    static unsigned long total;

    int width, height, color;

public:

    Window() = delete;
    Window(int width, int height, int color) : width(width), height(height), color(color)
        { total++; }
    
    ~Window()
        { total--; }

    static unsigned long get_total() { return total; }

    void set_size(int, int);
    void get_size(int&, int&);
    int get_color() { return color; }

};

void Window::set_size(int width, int height)
    { this->width = width; this->height = height; }

void Window::get_size(int& width, int& height)
    { width = this->width; height = this->height; }

unsigned long Window::total = 0;

int main()
{
    Window *ptr_wnd = new Window(200, 100, 255);

    // __ASSERT_TESTS__

    return 0;
}