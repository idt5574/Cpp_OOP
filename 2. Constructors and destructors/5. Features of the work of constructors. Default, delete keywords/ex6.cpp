#include <iostream>

class Operator {
    long a {0}, b {0}, c {0};

    Operator() = default;
public:

    static Operator* create_obj() 
    {
        Operator * ptr_obj = new Operator();
        return ptr_obj;
    }
};
