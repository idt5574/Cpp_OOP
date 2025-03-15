#include <iostream>
#include <string>

class CommonInterface
{
public:

    virtual long long get_id() const = 0;
    virtual void set_id(long long id) = 0;

};

class Thing : public CommonInterface
{
    long long id {0};
    std::string name;
    int price {0};

public:

    Thing(long long id, const std::string& name, int price)
    : id(id), name(name), price(price) {}

    virtual long long get_id() const
    { return id; }

    virtual void set_id(long long id)
    { this->id = id; }

    const std::string& get_name() const
    { return name; }

    int get_price() const
    { return price; }

};

enum { max_size = 100 };

int main()
{
    CommonInterface* lst[max_size] {
        new Thing{4, "Book C++", 2500},
        new Thing{1, "Computer HP", 125000},
        new Thing{10, "Mouse Lg", 4300},
        new Thing{19, "Monitor Samsung", 9560}
    };

    //__ASSERT_TESTS__

    for(int i = 0; i < 4; i++)
    {
        std::cout << lst[i]->get_id() << ' ';
        delete lst[i];
    }

    std::cout << std::endl;

    return 0;
}