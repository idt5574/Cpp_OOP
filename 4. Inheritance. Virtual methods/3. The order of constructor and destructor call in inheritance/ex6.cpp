#include <iostream>
#include <string>

class Furniture
{
public:

    enum type_furniture {
        fr_none = 0,
        fr_table,
        fr_chair,
        fr_closet
    };

protected:

    short width {0},
        height {0},
        depth {0};
    
    type_furniture type {fr_none};

public:

    Furniture(short width, short height, short depth, type_furniture type)
    : width(width), height(height), depth(depth), type(type) {}

    void get_dims(short& width, short& height, short& depth)
    { width = this->width; height = this->height; depth = this->depth; }

    type_furniture get_type() const
    { return type; }

};

class Table : public Furniture
{
    std::string model;

public:

    Table(const std::string& model, short width, short height, short depth)
    : Furniture(width, height, depth, fr_table), model(model) {}

    const std::string& get_model() const
    { return model; }

};

class Chair : public Furniture
{
    int color {0},
        weight {0};

public:

    Chair(short width, short height, short depth, int color, int weight)
    : Furniture(width, height, depth, fr_chair), color(color), weight(weight) {}

    void get_data(int& color, int& weight)
    { color = this->color; weight = this->weight; }

};

int main()
{
    Furniture* fr_lst[5] {
        new Table{"Черноземья стол 10", 10, 20, 30},
        new Table{"Белоземья стол 21", 6, 5, 22},
        new Chair{3, 5, 7, 132, 1650},
        new Chair{3, 6, 5, 200, 1750},
        new Table{"Бурый стол", 11, 6, 8}
    };

    // __ASSERT_TESTS__

    for(int i = 0; i < 5; i++) delete fr_lst[i];

    return 0;
}
