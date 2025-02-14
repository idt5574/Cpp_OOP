#include <iostream>
#include <cstring>

const char operators[] = "-+.\0";
const char alph[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0";

class ConvertToInt
{
public:
	ConvertToInt()
	{}

	int operator() (const char* str)
	{
		if(strpbrk(str, alph) != nullptr) return 0;
		return atoi(str);
	}
};



int main()
{
	std::string digit;
    	getline(std::cin, digit);

    	const char* str = digit.c_str(); // массив символов char с прочитанной строкой
	
	ConvertToInt str_to_int;
	std::cout << str_to_int(str) << std::endl;


	return 0;
}
