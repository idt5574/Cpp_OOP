#include <iostream>

class TriangleChecker
{
    int a, b, c;

public:

    TriangleChecker(int x=0, int y=0, int z=0) : a(x), b(y), c(z)
        { }

    int is_triangle()
    {
        if(a <= 0 || b <= 0 || c <= 0) return 1;

        if(a + b <= c || a + c <= b || b + c <= a) return 2;

        return 3;
    }
};

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    TriangleChecker* ptr_tr = new TriangleChecker(a, b, c);
    std::cout << ptr_tr->is_triangle() << std::endl;

    // __ASSERT_TESTS__

    delete ptr_tr;

    return 0;
}