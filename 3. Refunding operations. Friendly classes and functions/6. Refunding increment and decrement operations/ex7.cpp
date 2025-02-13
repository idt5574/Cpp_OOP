#include <iostream>
#include <cstring>

class StringBuffer
{
	enum {max_size = 1024};
	char *buffer {nullptr};
	int size {0};

public:
	StringBuffer(const char* str)
	{
		size = 0;
		while(str[size] != '\0' && size < max_size - 1)
			size++;

		buffer = new char[size + 1];
		for(int i = 0; i < size; ++i)
			buffer[i] = str[i];

		buffer[size] = '\0';
	}

	StringBuffer(const StringBuffer& other) : StringBuffer(other.buffer)
	{}

	~StringBuffer() { delete[] buffer; }

	const char* get_data() { return buffer; }
	int get_size() { return size; }

	const StringBuffer operator=(const StringBuffer& other)
	{
		if(this == &other)
			return *this;

		delete[] buffer;
		buffer = new char[other.size];

		for(int i = 0; i < other.size; i++)
			buffer[i] = other.buffer[i];

		size = other.size;

		return *this;
	}

	const StringBuffer operator+=(const char* other)
	{
		int new_size = size + strlen(other);
		char* new_char = new char[new_size];
		int cur_idx {0};

		for(int i = 0; i < size && cur_idx < new_size; ++i)
			new_char[cur_idx++] = buffer[i];

		for(int i = 0; i < strlen(other) && cur_idx < new_size; ++i)
			new_char[cur_idx++] = other[i];

		delete[] buffer;
		buffer = new_char;
		size = new_size;

		return *this;
	}

	friend StringBuffer operator+(const StringBuffer& left, const StringBuffer& right);
};


StringBuffer operator+(const StringBuffer& left, const StringBuffer& right)
{
	int new_size = left.size + right.size;	
	char* new_str = new char[new_size];
	int cur_idx {0};
	for(int i = 0; i < left.size && cur_idx < new_size ; ++i)
		new_str[cur_idx++] = left.buffer[i];

	for(int i = 0; i < right.size && cur_idx < new_size; ++i)
		new_str[cur_idx++] = right.buffer[i];

	return StringBuffer(new_str);
}

