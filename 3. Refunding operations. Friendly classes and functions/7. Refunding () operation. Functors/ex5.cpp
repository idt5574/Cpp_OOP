#include <iostream>
#include <string>
#include <ctime>

class RandomPassword
{
	std::string psw_chars;
	int min_length, max_length;

public:
	RandomPassword(const char* psw_chars, int min_length, int max_length)
		: psw_chars(psw_chars), min_length(min_length), max_length(max_length)
	{}

	std::string operator() ()
	{
		std::srand(time(0));
		int len = rand() % (max_length - min_length + 1) + min_length;
		std::string pass = "";

		for(int i = 0; i < len; ++i)
			pass.append(1, psw_chars[rand() % (psw_chars.length() - 0 + 1) + 0]);

		return pass;
	}
};
