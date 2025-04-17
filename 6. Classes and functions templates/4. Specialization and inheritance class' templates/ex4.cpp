#include <iostream>
#include <string>

class Person {
protected:
    std::string fio;
    short old {0};
public:
    Person(const std::string& fio, short old) : fio(fio), old(old)
        { }
    virtual ~Person() { }
    const std::string& get_fio() const { return fio; }
    short get_old() const { return old; }       
};

template <typename T>
class Array {
public:
    enum {max_array_size = 100};
protected:
    T data_array [max_array_size] {0}; // массив целых чисел
    int length_array {0}; // длина массива
public:
    Array() = default;
    Array(T* d, int size)
    {
        length_array = (size > max_array_size) ? max_array_size : size;
        for(int i = 0;i < length_array; ++i)
            data_array[i] = d[i];
    }
    virtual ~Array() { }

    T* get_data() { return data_array; }
    int get_length() { return length_array; }
};

template <typename T>
class Student : public Person, public Array<T>
{
    std::string group;

public:

    Student(const std::string& fio, short old) : Person(fio, old) {}
    Student(const std::string& fio, short old, T* array, size_t size) : Person(fio, old), Array<T>(array, size) {}

    void set_group(const std::string& group)
    {
        this->group = group;
    } // заносит в поле group переданную строку

    const std::string& get_group() const
    {
        return group;
    } // возвращает значение поля group

};

int main()
{
    short ar[] = {3, 3, 4, 2};
    Student<short>* ptr_st = new Student<short>{"Bechterev S. A.", 52, ar, 4};

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    delete ptr_st;

    return 0;
}