#include <iostream>

template <typename T>
class Array {
    T* data {nullptr};
    size_t size {0};
public:
    Array() = default;
    Array(T* d, size_t size) : size(size)
    {
        data = new T[size];

        for(T i = 0; i < size; i++)
            data[i] = d[i];
    }
    Array(const Array& other) : size(other.size)
    {
        data = new T[size];

        for(int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~Array() { delete[] data; }

    Array operator+(const Array& right)
    {
        size_t new_size = size + right.size;
        Array array_obj;

        array_obj.size = new_size;
        array_obj.data = new T[new_size];

        int j = 0;
        for(int i = 0; i < size; i++, j++)
            array_obj.data[j] = data[i];

        for(int i = 0; i < right.size; i++, j++)
            array_obj.data[j] = right.data[i];
       
        return array_obj;
    }
    const Array& operator=(const Array& right)
    {
        if(this == &right)
            return *this;

        delete[] data;

        size = right.size;
        data = new T[size];

        for(int i = 0; i < size; i++)
            data[i] = right.data[i];

        return *this;
    }

    const T* get_data() const { return data; }
    size_t get_length() const { return size; }
};
