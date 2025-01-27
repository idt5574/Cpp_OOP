#include <iostream>

using std::cout;
using std::endl;

class VectorN
{
    int dims {0};
    short* coords {nullptr};

public:

    VectorN()
        {}
    
    VectorN(int dims)
    { 
        this->dims = dims; 
        coords = new short[dims]{0};
    }

    VectorN(short a, short b)
    {
        dims = 2;
        coords = new short[dims] {a, b};
    }

    VectorN(short* coords, int dims)
    {
        this->dims = dims;
        this->coords = coords;
    }

    ~VectorN()
    {
        cout << "delete coords:";
        for(int i = 0; i < dims; i++)
        {
            cout << ' ' << coords[i];
            coords[i] = 0;
        }
        cout << endl;
    }

    const short* get_coords();
    int get_dims();
};

const short* VectorN::get_coords(){
    return coords;
}

int VectorN::get_dims(){
    return dims;
}