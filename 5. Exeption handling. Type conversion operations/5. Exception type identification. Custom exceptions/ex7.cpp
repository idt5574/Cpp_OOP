#include <iostream>

class BoxError : public std::exception
{
protected:
    std::string msg;

public:
    BoxError(const std::string error) noexcept : msg(error) {}

    const char * what() const noexcept override { return msg.data(); }

    virtual ~BoxError() {}

};

class BoxLimitError : public BoxError
{
public:
    BoxLimitError(const std::string error) : BoxError(error) {}

    ~BoxLimitError() {}
};

class BoxCalcError : public BoxError
{
public:
    BoxCalcError(const std::string error) : BoxError(error) {}

    ~BoxCalcError() {}
};

class Box3D
{
    enum {limit_dim = 100};
    short a{0}, b{0}, c{0};

public:

    Box3D() = default;
    Box3D(int a, int b, int c)
    {
        if(a < 0 || a > limit_dim || b < 0 || b > limit_dim || c < 0 || c > limit_dim)
            throw BoxLimitError("Exceeding the size range.");
        
        this->a = a; this->b = b; this->c = c;
    }

    void get_dims(short& a, short& b, short& c)
    {
        a = this->a; b = this->b; c = this->c;
    }

    void set_dims(short a, short b, short c)
    {
        if(a < 0 || a > limit_dim || b < 0 || b > limit_dim || c < 0 || c > limit_dim)
            throw BoxLimitError("Exceeding the size range.");

        
        this->a = a;
        this->b = b;
        this->c = c;
    }

    Box3D operator + (const Box3D& other)
    {
        if(a + other.a > limit_dim || b + other.b > limit_dim || c + other.c > limit_dim)
            throw BoxCalcError("Calculation: Exceeding the size range.");
        
        Box3D result {a + other.a, b + other.b, c + other.c};

        return result;
    }

    Box3D operator - (const Box3D& other)
    {
        if(a - other.a < 0 || b - other.b < 0 || c - other.c < 0)
            throw BoxCalcError("Calculation: Exceeding the size range.");
        
        Box3D result {a - other.a, b - other.b, c - other.c};

        return result;
    }

    Box3D& operator = (const Box3D& other)
    {
        if(this == &other)  
            return *this;

        this->a = other.a;
        this->b = other.b;
        this->c = other.c;

        return *this;
    }

};

int main()
{
    try
    {
        Box3D box {5, -1, 10};
    }
    catch(const BoxLimitError& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const BoxCalcError& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const BoxError& e)
    {
        std::cout << e.what() << std::endl;
    }

    // __ASSERT_TESTS__

    return 0;
}