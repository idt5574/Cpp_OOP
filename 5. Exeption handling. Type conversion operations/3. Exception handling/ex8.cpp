#include <iostream>

class Vector3D
{
    enum {min_coord = -100, max_coord = 100};
    int x{0}, y{0}, z{0};

    class Item
    {
        Vector3D* current {nullptr};
        short index {-1};

    public:

        Item(Vector3D* obj, short index)
        {
            if(index > 2 || index < 0) throw "Incorrect index.";
            
            this->index = index;
            current = obj;
        }

        operator int() const
        {
            switch (index)
            {
            case 0:
                return current->x;
            
            case 1:
                return current->y;

            case 2: 
                return current->z;
            }
        }

        void operator=(int other)
        {
            switch (index)
            {
            case 0:
                current->x = other; break;
            
            case 1:
                current->y = other; break;

            case 2: 
                current->z = other; break;
            }            
        }
    };

public:

    Vector3D(int x = 0, int y = 0, int z = 0)
    {
        if(x < min_coord || x > max_coord || y < min_coord || y > max_coord || z < min_coord || z > max_coord)
            throw -2;

        this->x = x;
        this->y = y;
        this->z = z;
    }

    void get_coords(int& x, int& y, int& z) const
    { x = this->x; y = this->y; z = this->z; }

    void set_coords(int x, int y, int z)
    {
        if(x < min_coord || x > max_coord || y < min_coord || y > max_coord || z < min_coord || z > max_coord)
            throw -1;
            
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Item operator [] (short index)
    {
        return Item(this, index);
    }

};

int main()
{
    try
    {
        Vector3D v3 {10, 1000, -500};
    }
    catch(int e)
    {
        std::cout << e << std::endl;
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
    }
    
    // __ASSERT_TESTS__

    return 0;
}