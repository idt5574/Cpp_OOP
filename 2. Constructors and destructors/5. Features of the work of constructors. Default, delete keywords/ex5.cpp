#include <iostream>

class Operator {
    long a {0}, b {0}, c {0};

    Operator(Operator& op) = default;
public:
    Operator() = default;

    Operator* create_copy() 
    {
        Operator * ptr_obj = new Operator(*this);
        return ptr_obj;
    }
};