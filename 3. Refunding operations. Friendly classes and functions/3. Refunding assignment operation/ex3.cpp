#include <iostream>

class Array {
    int* data {nullptr};
    size_t size {0};
public:

    Array() = default;

    Array(const int* data, size_t size) : size(size)
    {
        this->data = new int[this->size];

        for(int i = 0; i < this->size; i++)
            this->data[i] = data[i];
    }

    Array(const Array& other) : Array(other.data, other.size)
        { }

    void set_data(int* d, size_t length)
    {
        delete[] data;
        size = length;
        data = new int[size];

        for(size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    int* get_data() { return data; }
    size_t get_size() const { return size; }

    ~Array() { delete[] data; }

    Array operator +(const Array& right)
    {
        size_t new_size = size + right.size;
        int* new_data = new int[new_size];
        int cur_index = 0;

        for(int i = 0; i < size; i++)
            new_data[cur_index++] = data[i];

        for(int i = 0; i < right.size; i++)
            new_data[cur_index++] = right.data[i];

        Array new_array(new_data, new_size);
        delete[] new_data;

        return new_array;
    }

    const Array& operator =(const Array& other)
    {
        if(this == &other)
            return other;

        size = other.size;

        delete[] data;
        data = new int[size];

        for(int i = 0; i < size; i++)
            data[i] = other.data[i];

        return *this;
    }
};

int main()
{
    int d1[5] = {1, 2, 3, 4, 5};
    int d2[5] = {6, 7, 8, 9, 10};
    int d3[5] = {11, 12, 13, 14, 15};

    Array ar;
    Array ar1(d1, 5);
    Array ar2(d2, 5);
    Array ar3(d3, 5); // в массив data копируются данные из массива d; поле size = std::size(d)

    Array res_1;
    res_1 = ar1 + ar2; // объединение значений массивов data (по порядку) в единый массив; size - итоговая длина результирующего массива data

    Array res_2 = ar1 + ar2 + ar3;

    return 0;
}