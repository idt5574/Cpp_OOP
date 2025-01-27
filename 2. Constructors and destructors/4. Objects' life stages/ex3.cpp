#include <iostream>

class Graph
{
    double* data {nullptr};
    int length {0};

public:

    Graph() 
        { }

    Graph(const double* ar, int size) : length(size)
    { 
        data = new double[length] {0.0};
        for(int i = 0; i < length; i++)
            data[i] = ar[i];
    }
    
    ~Graph()
    {
        delete[] data;
    }

    void set_data(const double* ar, int size)
    {
        delete[] data;
        data = new double[size] {0.0};

        for(int i = 0; i < size; i++)
            data[i] = ar[i];
        
        length = size;
    }

    double* get_data()
        { return data; }
    
    int get_length()
        { return length; }

};

int main(void)
{
    double coords[] = {5, 0.4, 2.7, -3.2};
    Graph gr(coords, sizeof(coords)/sizeof(*coords));

    // __ASSERT_TESTS__ 

    return 0;
}