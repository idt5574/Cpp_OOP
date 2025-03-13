#include <iostream>
#include <string>

class Equipment
{
    unsigned long uid {0};

    static unsigned long cur_uid;

protected:

    bool is_exist {false};

public:

    Equipment(bool is_exist = false)
    : is_exist(is_exist), uid(cur_uid++) {}

    unsigned long get_uid() const
    { return uid; }

    virtual void print() const {}

    virtual ~Equipment() {}

};

unsigned long Equipment::cur_uid = 1;

class PC : public Equipment
{
    std::string model;
    int price {0};

public:

    PC(const std::string& model, int price, bool is_exist)
    : Equipment(is_exist), model(model), price(price) {}

    const std::string get_model() const
    { return model; }

    int get_price() const
    { return price; }

    virtual void print() const
    { std::cout << "PC: " << model << ", " << price << ", " << is_exist << std::endl; }

    virtual ~PC() 
    { puts("~PC"); }

};

int main()
{
    Equipment eq1; // is_exists = false; uid = 1
    Equipment eq2(true); // is_exists = true; uid = 2

    PC pc("model", 12, true);

    pc.print();

    return 0;
}