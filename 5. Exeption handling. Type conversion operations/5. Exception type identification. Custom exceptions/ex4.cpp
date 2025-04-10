#include <iostream>
#include <string>

class ArrayException : public std::exception
{
protected:
    std::string msg;

public:

    ArrayException(const char* str) noexcept : msg(str) {}
    ArrayException(const ArrayException& other) noexcept : msg(other.msg) {}

    const char * what() const noexcept override
    {
        return msg.c_str();
    }
};

int main()
{
    try
    {
        throw ArrayException("Main exception");
    }
    catch(const ArrayException& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    // __ASSERT_TESTS__

    return 0;
}