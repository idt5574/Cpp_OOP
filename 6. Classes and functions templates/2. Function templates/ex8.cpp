#include <iostream>

template <typename T>
void ar_sort(T* array, size_t size, bool (*filter) (T, T))
{
    for(int i = 0; i < size; i++)
        for(int j = i; j < size; j++)
            if(filter(array[j], array[i]))
            {
                T temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
}

int main()
{
    int data[] = {5, -3, 10, 0, 33, 7, -12};

    ar_sort<int>(data, 7, [] (int a, int b) -> bool { return abs(a) < abs(b); });

    // __ASSERT_TESTS__

    return 0;
}