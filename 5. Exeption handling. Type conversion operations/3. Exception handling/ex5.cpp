#include <iostream>

class ArrayInt
{
    int* data {nullptr};
    size_t size {0};

    class Item
    {
        ArrayInt* current {nullptr};
        int index {-1};

    public:
        
        Item(ArrayInt* obj, int index) : current(obj)
        {
            if(index < 0 || index >= current->size)
                throw "Incorrect index.";
            
            this->index = index;
        }

        operator int() const
        {
            return current->data[index];
        }

        void operator=(int other)
        {
            current->data[index] = other;
        }
    };

public:

    ArrayInt() = default;
    ArrayInt(int* data, size_t length)
    {
        set_data(data, length);
    }

    void set_data(int* d, size_t length)
    {
        size = length;

        if(data != nullptr)
            delete[] data;

        data = new int[size];

        for(int i = 0; i < size; i++)
            data[i] = d[i];
    }

    int* get_data() 
    { return data; }

    size_t get_size()
    { return size; }

    Item operator [](int index)
    { return Item(this, index); }

};