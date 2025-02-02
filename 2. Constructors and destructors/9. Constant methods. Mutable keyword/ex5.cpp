#include <iostream>

class CellItem {
    int row {0}, col {0};
    double data {0.0};

public:

    CellItem(int row=0, int col=0, double data=0.0) : row(row), col(col), data(data)
        {}

    double get_data() const
        { return data; } 
    
    int get_row() const
        { return row; }

    int get_col() const
        { return col; }

    void set_data(double d)
        { data = d; }

};

int main()
{
    CellItem cell{5, 7, 0.79};

    // __ASSERT_TESTS__

    return 0;
}