#include <iostream>
#include <string>

class ValueError : public std::exception
{
    std::string msg;

public:

    ValueError(const std::string error) : msg(error) {}

    const char * what() const noexcept override { return msg.c_str(); }

    ~ValueError() {};
};

class Window
{
    int width, height;

public:

    Window(int width, int height)
    {
        if(width <= 0 || height <= 0)
            throw ValueError("The value must be positive");

        this->width = width;
        this->height = height;
    }

    void get_data(int &width, int &height) const
    {
        width = this->width; height = this->height;
    }

};

class Rect
{
    double width, height;

public:

    Rect(double width, double height) 
    {
        if(width <= 0 || height <= 0)
            throw ValueError("The value must be positive");

        this->width = width;
        this->height = height;
    }

    void get_data(double &width, double &height) const
    {
        width = this->width; height = this->height;
    }

};

template <typename OT, typename FT = int>
FT get_square(const OT& object)
{
    FT w, h;
    object.get_data(w, h);

    return w * h;
}

int main()
{
    try
    {
        Window w {100, -5};
        int res_sq = get_square(w);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    // __ASSERT_TESTS__

    return 0;
}