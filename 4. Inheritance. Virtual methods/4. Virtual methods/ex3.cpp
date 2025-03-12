#include <iostream>
#include <string>

class Thing
{
protected:

    std::string name;
    int price {0};

public:

    Thing(const std::string name = "", int price = 0) 
    : name(name), price(price) {}

    const std::string& get_name() const
    { return name; }

    int get_price() const
    { return price; }

    virtual void print() const {}

};

class Table : public Thing
{
    int color {0};
    double weight {0};

public:

    Table(const std::string& name, int price, int color, double weight)
    : Thing(name, price), color(color), weight(weight) {}
    
    void print() const
    { printf("Table: %s, %d, %d, %.2f\n", name.c_str(), price, color, weight); }

};

class TV : public Thing
{
    int size {0};

public:

    TV(const std::string& name, int price, int size)
    : Thing(name, price), size(size) {}

    void print() const
    { printf("TV: %s, %d, %d\n", name.c_str(), price, size); }

};

class Cart
{
    enum { max_total_thing = 100 };
    Thing* goods[max_total_thing] {nullptr};
    int count {0};

public:

    void append(Thing* th)
    {
        if(count >= max_total_thing) return;
        goods[count++] = th;
    }

    Thing** get_goods() { return goods; }
    int get_count() const { return count; }

    void show() const
    {
        for(int i = 0; i < count; i++)
            goods[i]->print();
    }

    ~Cart()
    {
        for(int i = 0; i < count; i++)
        {
            if(!goods[i]) continue;

            delete goods[i];
        }
    }
};

int main()
{
    Cart cart;

    cart.append(new Table{"Стол", 12000, 0, 12.70});
    cart.append(new TV{"Panasonic", 54000, 43});
    cart.append(new TV{"Samsung", 83500, 54});
    cart.append(new Table{"Стол 2", 9500, 432, 10.74});

    cart.show();

    // __ASSERT_TESTS__

    return 0;
}