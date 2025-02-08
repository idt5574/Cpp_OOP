#include <iostream>

class Box3D {
	short a {0}, b {0}, c {0};

	class Item {
		Box3D* current {nullptr};
		int index {-1};

	public:
		Item(Box3D* obj, int index) : current(obj), index(index)
		{}

		int operator=(int right)
		{
			if(right > 0) {
				switch(index) {
					case 0:
						current->a = right;
						break;
					case 1:
						current->b = right;
						break;
					case 2:
						current->c = right;
						break;
				}
			}

			return right;
		}

		operator short() const
		{
			short return_value;

			switch(index) {
				case 0:
					return_value = current->a;
					break;
				case 1:
					return_value = current->b;
					break;
				case 2: 
					return_value = current->c;
					break;
				default:
					return_value = 0;
			}

			return return_value;
		}
	};

public:

	Box3D(short a=0, short b=0, short c=0)
	{
		this->a = a < 0 ? 0 : a;
		this->b = b < 0 ? 0 : b;
		this->c = c < 0 ? 0 : c;	
	}

	void get_dims(short& a, short &b, short& c) const
	{
		a = this->a; b = this->b; c = this->c;
	}

	void set_dims(short a, short b, short c)
	{
		if(a < 0 || b < 0 || c < 0) return;

		this->a = a;
		this->b = b;
		this->c = c;
	}

	operator int() { return a * b * c; }

	 Item operator [](int index)
        	{ return Item(this, index); }
};

int main()
{
	int indx = 1;

	Box3D b1;
	Box3D b2(1, 2, 3);

	Box3D b;
	b[0] = 10;
	b[1] = 20;
	b[2] = 30;
	int volume = b;
	short dim = b[indx];

	return 0;
}
