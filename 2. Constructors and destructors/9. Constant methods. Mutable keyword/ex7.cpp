#include <iostream>

class GamePole {
    int rows {0}, cols {0};
    char* pole {nullptr};

public:

    GamePole(int rows, int cols) : rows(rows), cols(cols)
    { 
        pole = new char[this->rows * this->cols] {0};
    }

    GamePole(const GamePole& other) : GamePole(other.rows, other.cols)
    {
        for(int i = 0; i < rows * cols; i++)
            pole[i] = other.pole[i];
    }

    void set_item(int row, int col, char value)
        { pole[row * cols + col] = value; }
    
    char get_item(int row, int col) const
        { return pole[row * cols + col]; }
    
    const char* get_pole() const
        { return pole; }
    
    void get_size(int& rows, int& cols)
        { rows = this->rows; cols = this->cols; }

    ~GamePole()
        { delete[] pole; }
};

int main()
{
    GamePole gp{10, 7};

    gp.set_item(3, 5, '#');
    gp.set_item(4, 2, '*');
    gp.set_item(4, 4, '*');

    // __ASSERT_TESTS__

    return 0;
}