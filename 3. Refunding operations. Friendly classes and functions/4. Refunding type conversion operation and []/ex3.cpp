#include <iostream>

class PointND {

	class Item {
		PointND* current {nullptr};
		int index {-1};

	public:
		Item(PointND* obj, int indx) : current(obj), index(indx)
		{}

		operator int() const
		{
			if(index < 0 || index >= current->dims)
				return 0;
			return current->coords[index];
		}

		void operator=(short right)
		{
			if(index < 0 || index >= current->dims)
				return;
			current->coords[index] = right;	
		}

	};

	short* coords {nullptr};
	size_t dims {0};

public:
	PointND() = default;
	PointND(short* cds, size_t len) : dims(len)
	{
		coords = new short[dims];
		for(size_t i = 0; i < dims; ++i)
			coords[i] = cds[i];
	}

	Item operator [](int indx)
	{
		return Item(this, indx);
	}

	const PointND& operator =(const PointND& other)
	{
		if(this == &other) return other;

		dims = other.dims;

		delete[] coords;
		coords = new short[dims];

		for(int i = 0; i < dims; i++)
			coords[i] = other.coords[i];
		
		return *this;
	}

	~PointND() { delete [] coords; }
};

int main()
{
	int indx1 = 1, indx2 = 2;

	short coords[] = {1, 2, 3, 4, 5};
	PointND pt(coords, std::size(coords));
	int val = pt[indx1];

	pt[indx2] = val;

	PointND pt2;
	pt2 = pt;
	
	std::cout << "pt: ";
	for(int i = 0; i < std::size(coords); ++i)
		std::cout << pt[i] << ' ';
	std::cout << std::endl;

	std::cout << "pt2: ";
	for(int i = 0; i < std::size(coords); ++i)
		std::cout << pt2[i] << ' ';
	std::cout << std::endl;

	return 0;
}
