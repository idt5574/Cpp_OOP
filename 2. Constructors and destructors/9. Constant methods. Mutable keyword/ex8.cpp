#include <iostream>

class GamePole {
    int rows {0}, cols {0};
    char* pole {nullptr};
    static GamePole* obj;

    GamePole(int rows, int cols) : rows(rows), cols(cols)
    { 
        pole = new char[this->rows * this->cols] {0};
    }

public:

    static GamePole* init(int rows, int cols)
    {
        if(obj == nullptr)
            obj = new GamePole(rows, cols);

        return obj;
    }

    GamePole(const GamePole& other) = delete;

    void set_item(int row, int col, char value)
        { pole[row * cols + col] = value; }
    
    char get_item(int row, int col) const
        { return pole[row * cols + col]; }
    
    const char* get_pole() const
        { return pole; }
    
    void get_size(int& rows, int& cols)
        { rows = this->rows; cols = this->cols; }

    ~GamePole()
    {
        delete[] pole;
        obj = nullptr;
    }
};

GamePole* GamePole::obj = nullptr;

int main()
{
    GamePole *ptr_pl = GamePole::init(5, 10);

    ptr_pl->set_item(1, 1, '@');
    ptr_pl->set_item(4, 9, '#');
    ptr_pl->set_item(3, 2, '*');

    // __ASSERT_TESTS__

    return 0;
}