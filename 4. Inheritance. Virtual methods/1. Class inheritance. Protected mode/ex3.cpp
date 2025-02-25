#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    short old {0};

public:

    Animal() = default;
    Animal(const char* name, short old) : name(name), old(old) {}

    const std::string& get_name() const { return name; }
    short get_old() const { return old; }
};

class Cat : public Animal
{
    int color {0};
    double weight {0.0};

public:
    Cat(const char* name, short old, int color, double weight)
    : Animal(name, old), color(color), weight(weight) {}

    int get_color() const { return color; }
    double get_weight() const { return weight; }
    void set_info(const std::string& name, short old, int color, double weight)
    {
        this->name = name;
        this->old = old;
        this->color = color;
        this->weight = weight;
    }
};

class Dog : public Animal
{
    std::string breed;
    short length {0};

public:

    Dog(const char* name, short old, std::string breed, short length)
    : Animal(name, old), breed(breed), length(length) {}

    const std::string& get_breed() const { return breed; }
    short get_length() const { return length; }
    void set_info(const std::string& name, short old, const std::string& breed, short length)
    {
        this->name = name;
        this->old = old;
        this->breed = breed;
        this->length = length;
    }
};