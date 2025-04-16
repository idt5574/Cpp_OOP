#include <iostream>

template <typename T>
struct Point
{
    T x{0}, y{0};

    Point() noexcept;
    Point(T, T);
};

template <typename D>
class Line
{
    Point<D> sp, ep;

public:

    Line() noexcept;
    Line(const Point<D>&, const Point<D>&);
    Line(D, D, D, D);

    Point<D> get_sp() const noexcept;
    Point<D> get_ep() const noexcept;

    void set_coords(const Point<D>&, const Point<D>&);
};

template <typename T>
Point<T>::Point() noexcept = default;

template <typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <typename D>
Line<D>::Line() noexcept = default;

template <typename D>
Line<D>::Line(const Point<D>& sp, const Point<D>& ep) : sp(sp), ep(ep) {}

template <typename D>
Line<D>::Line(D x0, D y0, D x1, D y1) : sp(x0, y0), ep(x1, y1) {}

template <typename D>
Point<D> Line<D>::get_sp() const noexcept
{
    return sp;
}

template <typename D>
Point<D> Line<D>::get_ep() const noexcept
{
    return ep;
}

template <typename D>
void Line<D>::set_coords(const Point<D>& sp, const Point<D>& ep)
{
    this->sp = sp;
    this->ep = ep;
}

int main()
{
    Line<unsigned> line {1, 2, 11, 54};

    // __ASSERT_TESTS__

    return 0;
}
