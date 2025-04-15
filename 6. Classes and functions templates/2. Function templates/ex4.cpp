#include <iostream>
#include <cmath>

template <typename T1, typename T2, typename T3>
auto tr_square(T1 a, T2 b, T3 c)
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{   
    auto res_1 = tr_square(10, 6, 8), 
        res_2 = tr_square(5.3, 2.7, 7),
        res_3 = tr_square(90, 'a', 55.4),
        res_4 = tr_square<int>(4, 5, 6);

    // __ASSERT_TESTS__

    return 0;
}