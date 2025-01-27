#include <iostream>
#include <string>

class Thing
{
    std::string name;
    double weight{0};
    int price{0};

public:
    
    Thing() : name("-") 
        { std::cout << "default constructor" << std::endl; }
    
    Thing(const std::string new_name) : name(new_name)
        { std::cout << "constructor 1" << std::endl; }

    Thing(const std::string name, double weight, double price) : Thing(name)
    {
        this->weight = weight;
        this->price = price;
        std::cout << "constructor 3" << std::endl;
    } 

    std::string get_name()
        { return name; }
    
    double get_weight()
        { return weight; }
    
    int get_price()
        { return price; }
};

int main(void)
{
    Thing *ptr_th = new Thing("HP Omen", 2.3, 120000);

    // __ASSERT_TESTS__

    delete ptr_th;

    return 0;
}