#include <iostream>
#include <cstring>

class Flower
{
    char name[100] = {0}; 
    int price {0}; 

public:

    Flower(const Flower& other) = delete;
    Flower(const char* name, int price) : price(price)
        { strcpy(this->name, name); }

    void get_data(char* name, int& price)
    {
        strcpy(name, this->name);
        price = this->price;
    }
};

int main(void)
{
    Flower flower("Тюльпан", 120);

    // __ASSERT_TESTS__ 

    return 0;
}