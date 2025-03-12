#include <iostream>
#include <string>

class Dish
{
protected:

    std::string name;
    int price {0};

public:

    Dish(const std::string& name, int price)
    : name(name), price(price) {}

    virtual void print_dish() const
    { printf("Dish: %s; %d\n", name.c_str(), price); }

};

class FishDish : public Dish
{
    int weight {0};

public:

    FishDish(const std::string& name, int price, int weight)
    : Dish(name, price), weight(weight) {}

    void print_dish() const
    { printf("FishDish: %s; %d; %d\n", name.c_str(), price, weight); }

};

class MeatDish : public Dish
{
    short fry_type {1};
    int weight {0};

public:

    MeatDish(const std::string name, int price, short fry_type, int weight)
    : Dish(name, price), fry_type(fry_type), weight(weight) {}

    void print_dish() const
    { printf("MeatDish: %s; %d; %d; %d\n", name.c_str(), price, fry_type, weight); }

};

int main()
{
    Dish* dishes[3] {
        new FishDish{"Устрицы", 900, 300},
        new MeatDish{"Бекон", 800, 2, 420},
        new FishDish{"Форель", 400, 210}
    };

    // __ASSERT_TESTS__

    for(int i = 0; i < 3; i++) 
    {
        dishes[i]->print_dish();
        delete dishes[i];
    }

    return 0;
}