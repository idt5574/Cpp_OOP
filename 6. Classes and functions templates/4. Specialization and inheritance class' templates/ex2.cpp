#include <iostream>

template <typename T>
class GraphInterface {
public:
    virtual void get_coords(T& x0, T& y0, T& x1, T& y1) const = 0;
    virtual void set_coords(T x0, T y0, T x1, T y1) = 0;
    virtual void draw() const = 0;
    virtual ~GraphInterface() { }
};

template <typename T>
class Ellipse : public GraphInterface<T>
{
    T x0 {0}, y0 {0}, x1 {0}, y1 {0};

public:

    Ellipse() = default;
    Ellipse(T x0, T y0, T x1, T y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}

    virtual void get_coords(T& x0, T& y0, T& x1, T& y1) const
    {
        x0 = this->x0; y0 = this->y0; x1 = this->x1; y1 = this->y1;
    }

    virtual void set_coords(T x0, T y0, T x1, T y1)
    {
        this->x0 = x0; this->y0 = y0; this->x1 = x1; this->y1 = y1;
    }

    virtual void draw() const
    {
        std::cout << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << std::endl;
    }
};

int main()
{
    GraphInterface<short>* lst[] = {new Ellipse<short>{-5, 10, 0, 11}, 
                                    new Ellipse<short>{5, 2, -4, -3}, 
                                    new Ellipse<short>{1, 5, 10, 22}};

    for(int i = 0; i < 3; i++)
        lst[i]->draw();

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    for(int i = 0; i < 3; i++)
        delete lst[i];

    return 0;
}