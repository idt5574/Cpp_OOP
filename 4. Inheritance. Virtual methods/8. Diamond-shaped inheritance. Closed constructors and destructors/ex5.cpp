#include <iostream>

class Object
{
private:

    ~Object() {}

public:

    Object() {}

    static void remove_object(Object* obj)
    {
        delete obj;
    }

};

int main(void)
{
    Object* ptr_obj = new Object;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}