#include <iostream>

int sum_ar(short* ar, size_t size)
{
    if(size == 0)
        throw "Array length is zero.";
    
    int res = 0;

    for(int i = 0; i < size; i++)
        res += ar[i];
    
    return res;
}

int main()
{
    short ar[] = {-1, 0, 10, 5, 3, 2};

    try
    {
        int sm = sum_ar(ar, 6);
        std::cout << sm << std::endl;
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
    }
    
    // __ASSERT_TESTS__

    return 0;
}
