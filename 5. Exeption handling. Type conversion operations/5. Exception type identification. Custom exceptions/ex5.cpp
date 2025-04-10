#include <iostream>
#include <string>

class VectorError : public std::exception
{
protected:
    std::string msg;

public:
    VectorError(const std::string& error) noexcept : msg(error)
        { }
    virtual ~VectorError() { }

    const char * what() const noexcept override { return msg.data(); }
};

class VectorErrorNegativeCoord : public VectorError
{
public:
    
    VectorErrorNegativeCoord() noexcept : VectorError("Negative coordinate value.") {}

    VectorErrorNegativeCoord(const std::string& error) noexcept : VectorError(error)
        { }
};

class Vector
{
    int x{0}, y{0};

public:

    Vector(int x = 0, int y = 0)
    {
        if(x < 0 || y < 0)
            throw VectorErrorNegativeCoord("Constructor: Negative coordinate value.");

        this->x = x;
        this->y = y;
    }

    int get_x() const noexcept
    {
        return x;
    }

    int get_y() const noexcept
    {
        return y;
    }

    void set_xy(int x, int y) 
    {
        if(x < 0 || y < 0)
            throw VectorErrorNegativeCoord();

        this->x = x;
        this->y = y;
    }
};

int main()
{
    int x, y;
    std::cin >> x >> y;

    try
    {
        Vector v (x, y);
        std::cout << v.get_x() << ' ' << v.get_y() << std::endl;
    }
    catch(const VectorErrorNegativeCoord& e)
    {
        std::cout << e.what() << '\n';
    }
    
    // __ASSERT_TESTS__

    return 0;
}