#include <iostream>

class Operator {
    int type {0};
    short operation {-1};

    Operator() = default;
    Operator(const Operator &other) = default;

public:

    static Operator* create()
    {
        return new Operator();
    }

    void set_state(int t, short o) { type = t; operation = o; }
    void get_state(int& t, short& o) { t = type; o = operation; }
};