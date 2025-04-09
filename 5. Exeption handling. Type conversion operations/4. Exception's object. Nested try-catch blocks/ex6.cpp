#include <iostream>
#include <string>
#include <cstring>

class ExceptionConvert
{
    std::string msg;

public:

    ExceptionConvert(const char* str) : msg(str) {}

    const std::string& to_msg() const
    {
        return msg;
    }
};

class ConvertToInt
{
    static const char kAcceplableCharacters[];

    void isValid(const char* str)
    {
        for(int i = 0; i < strlen(str); i++)
            if(strchr(kAcceplableCharacters, str[i]) == NULL)
                throw ExceptionConvert("Conversion error");
    }

public:
    ConvertToInt() = default;

    int operator () (const char* str)
    {
        isValid(str);

        return atoi(str);
    }
};

const char ConvertToInt::kAcceplableCharacters[] = "0123456789+-.";

int main()
{
    ConvertToInt str_to_int;
    std::string digit;

    while(true) {
        getline(std::cin, digit);
        const char* str = digit.c_str(); // массив символов char с прочитанной строкой
        int result;

        try
        {
            result = str_to_int(str);

            if(result == -41445828)
                break;

            std::cout << result << std::endl;
        }
        catch(const ExceptionConvert& e)
        {
            std::cout << e.to_msg() << std::endl;
        }
    }   
    
    // __ASSERT_TESTS__

    return 0;
}