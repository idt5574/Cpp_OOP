#include <iostream>

template <typename T>
T ar_sum(const T* array, size_t size, bool (*filter) (T))
{
    T res = 0;

    for(int i = 0; i < size; i++)
        if(filter(array[i]))
            res += array[i];

    return res;
}

int main()
{
    double data[] = {-1, 2.5, -3, -4, 5.1, 6};

    double res = ar_sum<double>(data, 6, [] (double a) -> bool { return a > 0; });

    // __ASSERT_TESTS__

    return 0;
}