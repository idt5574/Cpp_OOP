#include <iostream>

class FunctionInterface
{
public:

    virtual double func(double arg) { return 0; }
    virtual double operator() (double arg) { return 0; }

};

class LinearFunction : public FunctionInterface
{
    double k {0.0},
        b {0.0};
    
public:

    LinearFunction(double k, double b)
    : k(k), b(b) {}

    double func(double arg)
    { return k * arg + b; }

    double operator() (double arg)
    { return k * arg + b; }

};

class ReluFunction : public FunctionInterface
{
public:

    ReluFunction() = default;

    double func(double arg)
    { return (arg > 0 ? arg : 0); }

    double operator() (double arg)
    { return (arg > 0 ? arg : 0); }

};

int main()
{
    FunctionInterface* funcs[3] {
        new LinearFunction{0.5, 0},
        new LinearFunction{1.2, -5.4},
        new ReluFunction()
    };

    double user_arg;
    std::cin >> user_arg;

    // __ASSERT_TESTS__

    std::cout << std::fixed;
    std::cout.precision(2);
    for(int i = 0; i < 3; i++) 
    {
        std::cout << funcs[i]->func(user_arg) << ' ';
        delete funcs[i];
    }

    std::cout << std::endl;

    return 0;
}