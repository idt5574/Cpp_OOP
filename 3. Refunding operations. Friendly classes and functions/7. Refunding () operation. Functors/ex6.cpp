#include <iostream>
#include <cstring>
#include <string>

class ExtensionFilter
{
	std::string flt;

public:
	ExtensionFilter(const char* flt) : flt(flt)
	{}

	int operator() (std::string* lst, size_t size_lst, std::string* flt_lst, size_t max_count_files)
	{
		int count {0};
		for(int i = 0; i < size_lst && count < max_count_files; ++i)
		{
			if(strchr(lst[i].c_str(), '.') != nullptr && flt.find(strchr(lst[i].c_str(), '.')) != std::string::npos)
				lst[count++] = lst[i];
		}
		
		return count;
	}

};
