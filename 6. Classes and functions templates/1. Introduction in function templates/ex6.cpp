#include <iostream>
#include <cmath>

template <typename T>
double hypot(T a, T b)
{
    return sqrt(a * a + b * b);
}

int main()
{
    double h1 = hypot(1, 0.5),
        h2 = hypot(6.3, 0.8);

    // __ASSERT_TESTS__

    return 0;
}
