#include <iostream>
#include <string>

class Thing
{
protected:
    std::string name;
    int price {0};

public:
    
    Thing(const std::string& name, int price)
    : name(name), price(price) {}

    void set_base_info(const std::string& name, int& price)
    { this->name = name; this->price = price; }

    void get_base_info(std::string& name, int& price)
    { name = this->name; price = this->price; }

};

class TV : public Thing
{
    int size {0};
    double weight {0.0};

public:

    TV(const std::string& name, int price, int size, double weight)
    : size(size), weight(weight), Thing(name, price) {}

    void get_data(std::string& name, int& price, int& size, double& weight)
    { name = this->name; price = this->price; size = this->size; weight = this->weight; }

};

class Book : public Thing
{
    std::string author;
    int pages {0};

public:

    Book(const std::string& name, int price, const std::string& author, int pages)
    : author(author), pages(pages), Thing(name, price) {}

    void get_data(std::string& name, int& price, std::string& author, int& pages)
    { name = this->name; price = this->price; author = this->author; pages = this->pages; }

};

class Store
{
    enum { max_total = 100 };
    Thing* things[max_total] {nullptr};
    int total {0};

public:

    void append(Thing* th)
    {
        things[total++] = th;
    }

    Thing* operator[] (int index)
    {
        return things[index];
    }

    int get_total() const
    {
        return total;
    }
    
    ~Store()
    {
        for(int i = total - 1; i >= 0; i--)
            delete things[i];
    }

};

int main()
{
    Store st;
    st.append(new TV{"Samsung", 54300, 43, 5.4});
    st.append(new Book{"C++", 2000, "Balakirev", 543});
    st.append(new TV{"Sony", 97000, 80, 7.5});

    // __ASSERT_TESTS__

    return 0;
}