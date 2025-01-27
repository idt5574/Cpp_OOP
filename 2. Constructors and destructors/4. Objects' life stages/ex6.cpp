#include <iostream>
#include <string>

class Item {
    std::string name; // название программы
    unsigned short duration; // длительность в минутах

public:

    Item(std::string name="-", unsigned short duration=0)
        : name(name), duration(duration)
        { }

    std::string& get_name()
        { return name; }
    
    unsigned short get_duration()
        { return duration; }
    
};

class TVProg {
    enum {max_length = 100};
    Item items[max_length]; // программы 
    int count {0};  // число программ

public:

    TVProg()
        {}
    
    TVProg(const Item* list, int size) : count(size)
    {
        for(int i = 0; i < count; i++)
            items[i] = list[i];
    }

    void append(const Item& it)
    { 
        if(count == max_length) return;
        items[count++] = it; 
    }

    void append(const Item* lst, int length)
    {
        for(int i = 0; i < length && count < max_length; i++)
            items[count++] = lst[i];
    }

    Item* get_list()
        { return items; }
    
    int get_count()
        { return count; }

};

int main(void)
{
    Item lst[] = {
        {"Новости", 20},
        {"Модный приговор", 50},
        {"Жить здорово!", 60},
        {"Информационный канал", 15},
        {"Новости", 15},
        {"Давай поженимся!", 70}
    };

    TVProg tv = {lst, sizeof(lst) / sizeof(*lst)};

    // __ASSERT_TESTS__ 

    return 0;

}