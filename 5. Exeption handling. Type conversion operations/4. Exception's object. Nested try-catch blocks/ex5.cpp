#include <iostream>

class IndexError
{
public:
    IndexError() = default;
    ~IndexError() {}
};

class PointND
{
    double* coords {nullptr};
    size_t dims {0};

    class Item
    {
        PointND* current {nullptr};
        size_t index {0};

    public:
        
        Item(PointND* object, size_t index)
        {
            if(index >= object->dims) throw IndexError();

            current = object;
            this->index = index;
        }

        operator double() const
        {
            return current->coords[index];
        }

        void operator = (double other)
        {
            current->coords[index] = other;
        }
    };

public:

    PointND() = default;
    PointND(double* cds, size_t len) : dims(len)
    {
        coords = new double[dims];
        for(size_t i = 0; i < dims; i++)
            coords[i] = cds[i];
    }

    ~PointND() { delete[] coords; }

    size_t get_dims() const { return dims; }

    PointND& operator = (const PointND& other)
    {
        if(this == &other)
            return *this;

        delete[] coords;
        dims = other.dims;
        coords = new double[dims];

        for(size_t i = 0; i < dims; ++i)
            coords[i] = other.coords[i];
        
        return *this;
    }

    Item operator [] (size_t index)
    {
        return Item(this, index);
    }
};

int main()
{
    double coords[] = {0.1, 0.2, 0.5, -1.4};
    PointND pt {coords, 4};

    // __ASSERT_TESTS__

    return 0;
}