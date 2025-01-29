#include <iostream>

class Thing {
    long id {0};
    int price {0}; 
    double weight {0.0}; 

    bool check_price(int);
    bool check_weight(double);

public:

    Thing()
        {}
    
    Thing(long id, int price, double weight)
    {
        this->id = id;
        this->price = check_price(price) ? price : 0;
        this->weight = check_weight(weight) ? weight : 0;
    }

    void get_info(long&, int&, double&); 
};

bool Thing::check_price(int price)
    { return price >= 0; }

bool Thing::check_weight(double weight)
    { return weight >= 0; }

void Thing::get_info(long& id, int& price, double& weight)
{
    id = this->id;
    price = this->price;
    weight = this->weight;
}

int main()
{
    Thing th(5, 53403, 87.4);

    // __ASSERT_TESTS__

    return 0;
}