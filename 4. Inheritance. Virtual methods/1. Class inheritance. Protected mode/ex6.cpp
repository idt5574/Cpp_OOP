#include <iostream>
#include <string>

class Thing
{
    unsigned id {0};

protected:
    std::string name;
    int price {0};

public:

    Thing() = default;
    Thing(const std::string& name, int price)
    : name(name), price(price) {}

    void set_data(const std::string& name, int price)
    { this->name = name; this->price = price; }

    unsigned get_id() const { return id; }
    std::string get_name() const { return name; }
    int get_price() const { return price; }

};

class ThingPhisical : public Thing
{
    unsigned width {0}, height {0}, depth {0};
    double weight {0.0};

public:

    ThingPhisical() = default;
    ThingPhisical(const std::string& name, int price)
    : Thing(name, price) {}
    ThingPhisical(const std::string& name, int price, unsigned width, unsigned height, unsigned depth, double weight)
    : width(width), height(height), depth(depth), weight(weight), Thing(name, price) {}

    void set_dims(unsigned width, unsigned height, unsigned depth)
    { this->width = width; this->height = height; this->depth = depth; }
    void set_weight(double weight) { this->weight = weight; }

    void get_dims(unsigned& width, unsigned& height, unsigned& depth) const
    { width = this->width; height = this->height; depth = this->depth; }
    double get_weight() const { return weight; }
};

class ThingElectro : public Thing
{
    unsigned volume {0};

public:

    ThingElectro() = default;
    ThingElectro(const std::string name, int price)
    : Thing(name, price) {}
    ThingElectro(const std::string name, int price, unsigned volume)
    : volume(volume), Thing(name, price) {}

    void set_volume(unsigned volume) { this->volume = volume; }
    
    unsigned get_volume() const { return volume; }
};