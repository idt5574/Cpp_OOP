#include <iostream>
#include <string>

struct CPU {
    std::string model; // модель CPU
    double fr; // тактовая частота (в ГГц)

    CPU(std::string model="-", double fr=0.0) : model(model), fr(fr)
        {}
};

struct Memory {
    std::string name; // наименование
    unsigned long long volume; // размер памяти (в байтах)

    Memory(std::string name="-", unsigned long long volume=0LL) : name(name), volume(volume)
        {}
};

class MotherBoard {
    CPU cpu;
    Memory mems[2];
public:
    MotherBoard(const CPU& cpu, const Memory& mem_1, const Memory& mem_2)
     : cpu(cpu), mems {mem_1, mem_2}
        { }
    CPU& get_cpu() { return cpu; }
    Memory* get_mems() { return mems; }
};

int main(void)
{
    MotherBoard *ptr_mb = new MotherBoard((CPU){"CORE i5", 1.7}, (Memory){"Samsung", 4000000000}, (Memory){"Kingston", 8000000000});

    // __ASSERT_TESTS__ 

    delete ptr_mb;

    return 0;
}