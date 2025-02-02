#include <iostream>
#include <cstring>

class StringChars {
    char* buffer {nullptr};
    size_t length {0};

public:
    StringChars(const char* str) {
        length = strlen(str);
        buffer = new char[length + 1];
        strcpy(buffer, str);
    }

    StringChars(const StringChars& obj) {
        length = obj.length;
        buffer = new char[length + 1];
        strcpy(buffer, obj.buffer);
    }

    char* to_str() const {return buffer;}

    size_t get_length() const {return length;}

    StringChars operator+(const StringChars& obj) const {
        size_t newLength = length + obj.length;
        char* newBuffer = new char[newLength + 1];
        strcpy(newBuffer, buffer);
        strcat(newBuffer, obj.buffer);
        StringChars newObj(newBuffer);
        delete [] newBuffer;
        return newObj;
    }

    ~StringChars() { delete [] buffer; }
};

int main()
{
    StringChars *ptr_str1 = new StringChars("Language"), *ptr_str2 = new StringChars(" C++");
    StringChars res = *ptr_str1 + *ptr_str2; // buffer = "Hello, C++", length = 10

    // __ASSERT_TESTS__

    delete ptr_str1;
    delete ptr_str2;

    return 0;
}