#include <iostream>

class CoordsND
{
    enum {max_coords = 10};
    int *coords {nullptr};
    int size {0};

public:

    CoordsND(const CoordsND& other) : size(other.size)
    {
        coords = new int[size];

        for(int i = 0; i < size; i++)
            coords[i] = other.coords[i];
    }

    CoordsND(CoordsND&& move) noexcept : size(move.size)
    {
        coords = move.coords;
        move.coords = nullptr;
    }

    CoordsND(int* lst, int sz)
    {
        size = (sz > max_coords) ? max_coords : sz;

        coords = new int[size];
        for(int i = 0; i < size; i++)
            coords[i] = lst[i];
    }

    ~CoordsND() { delete[] coords; }

    int* get_coords() { return coords; }
    int get_size() const { return size; }

    const CoordsND& operator=(const CoordsND& other)
    {
        if(this == &other) return *this;

        delete[] coords;
        size = other.size;

        coords = new int[size];

        for(int i = 0; i < size; i++)
            coords[i] = other.coords[i];

        return *this;
    }
};