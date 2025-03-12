#include <iostream>

enum type_filter_water{
    flt_none = 0,
    flt_mechanical,
    flt_aragon,
    flt_calcium
};

class FilterWater
{
    unsigned date {0};
    type_filter_water type {flt_none};

public:

    FilterWater(unsigned date, type_filter_water type)
    : date(date), type(type) {}

    unsigned get_date() const
    { return date; }

    type_filter_water get_type() const
    { return type; }

};

class Mechanical : public FilterWater
{
public:

    Mechanical(unsigned date)
    : FilterWater(date, flt_mechanical) {}

};

class Aragon : public FilterWater
{
public:

    Aragon(unsigned date)
    : FilterWater(date, flt_aragon) {}

};

class Calcium : public FilterWater
{
public:

    Calcium(unsigned date)
    : FilterWater(date, flt_calcium) {}

};

class GeyserClassic
{
public:

    enum { total_slots = 3 };

private:

    FilterWater* slots[total_slots] {nullptr};

public:

    GeyserClassic(FilterWater* flt_1=nullptr, FilterWater* flt_2=nullptr, FilterWater* flt_3=nullptr)
    {
        slots[0] = flt_1;
        slots[1] = flt_2;
        slots[2] = flt_3;
    }

    const FilterWater* operator[] (int index) const
    {
        index--;

        if(index < 0 || index > 2)
            return nullptr;

        if(!slots[index])
            return nullptr;

        return slots[index];
    }

    void add_filter(int slot_num, FilterWater* filter)
    {
        if(slot_num - 1 < 0 || slot_num - 1 > 2)
            return;
        
        if(filter->get_type() != slot_num)
            return;

        slots[slot_num - 1] = filter; 
    }

};

int main()
{
    Mechanical filter_1(100);
    Aragon filter_2(100);
    Calcium filter_3(100);

    GeyserClassic gc_1;
    GeyserClassic gc_2(&filter_1); 
    GeyserClassic gc_3(&filter_1, &filter_2); 
    GeyserClassic gc_4(&filter_1, &filter_2, &filter_3); 

    return 0;
}