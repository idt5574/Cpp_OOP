#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    short old;

public:
    Animal(const std::string& name, short old)
    : name(name), old(old) {}
};

class Cat : public Animal
{
    int color {0};
    double weight {0};

public:
    Cat(const std::string& name, short old, int color, double weight)
    : color(color), weight(weight), Animal(name, old) {} 

    void get_data(std::string& name, short& old, int& color, double& weight)
    { name = this->name; old = this->old; color = this->color; weight = this->weight; }
};

class Dog : public Animal
{
    int height {0};
    int speed {0};

public:
    Dog(const std::string& name, short old, int height, int speed)
    : height(height), speed(speed), Animal(name, old) {}

    void get_data(std::string& name, short& old, int& height, int& speed)
    { name = this->name; old = this->old; height = this->height; speed = this->speed; }
};

int main()
{
    Cat cat_1 {"Zeus", 5, 0, 1.2},
        cat_2 {"Poseidon", 7, 122, 0.9};

    Dog dog_1 {"Rex", 10, 50, 32};
    
    // __ASSERT_TESTS__

    return 0;
}