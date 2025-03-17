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
    
    class IntegerArray {
    public:
        enum {max_array_size = 100};
    protected:
        int data_array [max_array_size] {0}; // массив целых чисел
        int length_array {0}; // длина массива
    public:
        IntegerArray() = default;
        IntegerArray(int* d, int size)
        {
            length_array = (size > max_array_size) ? max_array_size : size;
            for(int i = 0;i < length_array; ++i)
                data_array[i] = d[i];
        }
        virtual ~IntegerArray() { }
    
        int* get_data() { return data_array; }
        int get_length() const { return length_array; }
    };
    

    class Student : public Person, public IntegerArray
    {
        std::string group;
    
    public:

        Student(const std::string& fio, short old)
        : Person(fio, old) {}

        Student(const std::string& fio, short old, int* data_array, int length_array)
        : Person(fio, old), IntegerArray(data_array, length_array) {}

        void set_group(const std::string& group)
        { this->group = group; }

        const std::string& get_group() const
        { return group; }

    };

    int main()
    {
        int ar[] {5, 4, 3, 4, 5};
        Student* ptr_st = new Student{"Евстигнеев А.Б.", 23, ar, 5};

        // __ASSERT_TESTS__

        delete ptr_st;

        return 0;
    }