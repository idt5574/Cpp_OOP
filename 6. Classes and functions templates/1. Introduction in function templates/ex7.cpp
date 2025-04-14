#include <iostream>

template <typename AR>
AR ar_sum_positive(AR* array, size_t size)
{
    AR res = 0;

    for(int i = 0; i < size; i++)
        res += array[i] > 0 ? array[i] : 0;

    return res;
}

int main()
{
    float d1[] = {0.1f, 2.4f, 1.5f, -0.3f, 1.0f, -11.5f};
    double d2[] = {-4.3, 0.8, 15.3, -0.01, -1.2, -6.5};
    int d3[] = {6, 4, -1, -3, 0, 10, 8, -1, 2};

    float s1 = ar_sum_positive(d1, std::size(d1));
    double s2 = ar_sum_positive(d2, std::size(d2));
    int s3 = ar_sum_positive(d3, std::size(d3));

    // __ASSERT_TESTS__

    return 0;
}