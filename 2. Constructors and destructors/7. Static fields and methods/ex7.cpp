#include <iostream>

class Array {
    double* data {nullptr};
    size_t size {0};

    Array() = default;
    Array(const Array& other) = default;

public:

    static Array* create(size_t);
    static Array* create(double* ar, size_t size);

    void set_data(double* d, size_t length)
    {
        delete[] data;
        size = length;
        data = new double[size];

        for(size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    double* get_data() { return data; }
    size_t get_size() { return size; }

    ~Array()
        { delete[] data; }
};

Array* Array::create(size_t size)
{
    Array *new_array = new Array();
    
    new_array->size = size;
    new_array->data = new double[size] {0.0};

    return new_array;
}

Array* Array::create(double* ar, size_t size)
{
    Array *new_array = new Array();
    
    new_array->set_data(ar, size);

    return new_array;
}