#include <iostream>
#include <cstring>

class CartData {
    unsigned long id;
    char name[100];
    unsigned price;
    double weight;

public:
    void get_data(unsigned long &id, unsigned &price, double &weight) {
        id = this->id;
        price = this->price;
        weight = this->weight;
    }

    char* get_name() {
        return name;
    }

    void set_data(unsigned long id, const char* name, unsigned price, double weight) {
        this->id = id;
        this->price = price;
        this->weight = weight;
        strcpy(this->name, name);
    }
};

int main() {
    CartData item;
    item.set_data(10, "Toy", 2000, 5.45);

    // __ASSERT_TESTS__
    return 0;
}