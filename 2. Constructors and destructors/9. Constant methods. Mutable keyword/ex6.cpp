#include <iostream>

class BoxDims {
    unsigned short dimension {0};
    unsigned* dims {nullptr};

public:

    BoxDims(const BoxDims&) = delete;
    BoxDims(unsigned data) : dimension(1)
    {
        dims = new unsigned(data);
    }

    BoxDims(unsigned data1, unsigned data2) : dimension(2)
    {
        dims = new unsigned[dimension] {data1, data2};
    }

    BoxDims(unsigned data1, unsigned data2, unsigned data3) : dimension(3)
    {
        dims = new unsigned[dimension] {data1, data2, data3};
    }

    BoxDims(const unsigned* dims, unsigned short dimension) : dimension(dimension)
    {
        this->dims = new unsigned[dimension] {0};

        for(int i = 0; i < dimension; i++)
            this->dims[i] = dims[i];
    }

    void set_dims(const unsigned*);

    unsigned short get_dimension() const
        { return dimension; }

    const unsigned* get_dims() const
        { return dims; }
    
    unsigned get_volume() const;

    ~BoxDims()
        { delete[] dims; }

};

void BoxDims::set_dims(const unsigned* dims)
{
    for(int i = 0; i < dimension && i < (sizeof(dims) / sizeof(unsigned)); i++)
        this->dims[i] = dims[i];
}

unsigned BoxDims::get_volume() const 
{
    { 
        unsigned result = 1;

        for(int i = 0; i < dimension; i++)
            result *= dims[i];

        return result;
    }
}

int main()
{
    BoxDims box{3, 10, 5};

    unsigned ar[] = {1, 2, 4};

    unsigned* ptr_ar = new unsigned[3] {1, 2, 4};
    ptr_ar[0] = 1;
    ptr_ar[1] = 2;
    ptr_ar[2] = 4;

    std::cout << "Size of ptr_ar: " << sizeof(ptr_ar) << std::endl;
    std::cout << "Size of ar: " << sizeof(ar) << std::endl;
    std::cout << "Size of unsigned: " << sizeof(unsigned int) << std::endl << std::endl;

    std::cout << "Start dims: " << box.get_dims()[0] << ' ' << box.get_dims()[1] << ' ' << box.get_dims()[2] << std::endl;

    box.set_dims(ptr_ar);

    std::cout << "Setted dims: " << box.get_dims()[0] << ' ' << box.get_dims()[1] << ' ' << box.get_dims()[2] << std::endl;

    // __ASSERT_TESTS__

    delete[] ptr_ar;

    return 0;
}