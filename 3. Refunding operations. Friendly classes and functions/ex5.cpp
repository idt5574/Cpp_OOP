#include <iostream>

class BottleWater
{
    enum {max_volume = 320}; // максимальный объем воды
    unsigned volume {0}; // объем воды в бутылке
public:

    BottleWater(unsigned volume = 0) : volume(volume > max_volume ? max_volume : volume)
        { }

    BottleWater(const BottleWater& other) : volume(other.volume)
        { }

    unsigned get_volume() const { return volume; }

    unsigned operator +(const BottleWater other)
    {
        return (volume + other.volume) > max_volume ? max_volume : volume + other.volume;
    }
};

int main(void)
{
    BottleWater b1(10), b2(100);
    BottleWater res_1 = b1 + b2; // res_1: volume = 110
    BottleWater res_2 = b2 + 300; // res_2: volume = 320

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}