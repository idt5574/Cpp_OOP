#include <iostream>

class TicTacToe {

	
	class Item {
		unsigned short cell_index {0}, row_index {0};
		TicTacToe* current {nullptr};

	public:
		Item(TicTacToe* obj, unsigned short row_index, unsigned short cell_index)
			: current(obj), row_index(row_index), cell_index(cell_index)
		{}
		
		operator char() const
		{
			if(cell_index < 0 || cell_index > 2 || row_index < 0 || row_index > 2)
				return 0;
			
			return current->pole[row_index * current->size_pole + cell_index];	
		}

		void operator=(const char right)
		{
			if(cell_index < 0 || cell_index > 2 || row_index < 0 || row_index > 2)
				return;

			current->pole[row_index * current->size_pole + cell_index] = right;		
		}
	};

	class RowData {
	

		unsigned short row_index {0};
		TicTacToe* current {nullptr};
	public:
		RowData(TicTacToe* obj, unsigned short row_index) : 
			row_index(row_index), current(obj)
			{};
		Item operator[] (unsigned short cell_index)
		{
			return Item(current, row_index, cell_index);
		}
			
	};

	enum { size_pole = 3 };
	char pole[size_pole * size_pole] {0};

public:

	TicTacToe() = default;

	const char* get_pole() const { return pole; }
	int get_size() const { return size_pole; }

	void show_pole()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
				std::cout << pole[i * size_pole + j] << ' ';
			std::cout << std::endl;
		}
	}
	
	RowData operator [](unsigned short row_index)
	{ return RowData(this, row_index); }

};

int main()
{
	TicTacToe *ptr_game = new TicTacToe();
	(*ptr_game)[0][0] = 'x';
	(*ptr_game)[1][1] = 'x';
	(*ptr_game)[2][2] = 'x';

	ptr_game->show_pole();	

	// __ASSERT_TESTS__

	delete ptr_game;

	return 0;
}
