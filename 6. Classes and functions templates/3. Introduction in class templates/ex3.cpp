#include <iostream>

template <typename T>
class Vector2D
{
    T x{0}, y{0};

public:

    Vector2D();
    Vector2D(T, T);

    T get_x() const;
    T get_y() const;

    void set_xy(T, T);

};

template <typename T>
Vector2D<T>::Vector2D() = default;

template <typename T>
Vector2D<T>::Vector2D(T x, T y) : x(x), y(y) {}

template <typename T>
T Vector2D<T>::get_x() const
{
    return x;
}

template <typename T>
T Vector2D<T>::get_y() const
{
    return y;
}

template <typename T>
void Vector2D<T>::set_xy(T x, T y)
{
    this->x = x; this->y = y;
}

int main()
{
    Vector2D vector {-54.2, 10.8};
    
    // __ASSERT_TESTS__

    return 0;
}