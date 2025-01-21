#include <iostream>

class Goods {
public:
    std::string name;
    double weight;
    int price;

    const std::string& get_name() 
        { return name; }
    
    double get_weight()
        { return weight; }
    
    int get_price()
        { return price; }
};

int main() {
    Goods book{"Основы ООП", 234.5, 2000}, toy{"Oculus Quest 3", 204.6, 80000};

    // __ASSERT_TESTS__
    return 0;
}