#include <iostream>

enum type_life {
    lf_protists = 1,
    lf_plants = 2,
    lf_animals = 3,
    lf_mosses = 4,
    lf_flowering = 5,
    lf_worms = 6,
    lf_mammals = 7,
    lf_human = 8,
    lf_monkeys = 9
};

class Protists {
    const type_life type {lf_protists}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Protists() { }
};

class Plants : public Protists {
    const type_life type {lf_plants}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Plants() { }
};

class Animals : public Protists {
    const type_life type {lf_animals}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Animals() { }
};

class Mosses : public Plants {
    const type_life type {lf_mosses}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Mosses() { }
};

class Flowering : public Plants {
    const type_life type {lf_flowering}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Flowering() { }
};

class Worms : public Animals {
    const type_life type {lf_worms}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Worms() { }
};

class Mammals : public Animals {
    const type_life type {lf_mammals}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Mammals() { }
};

class Human : public Mammals {
    const type_life type {lf_human}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Human() { }
};

class Monkeys : public Mammals {
    const type_life type {lf_monkeys}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Monkeys() { }
};

int main(void)
{
    Protists* life[] {
        new Plants(),
        new Flowering(),
        new Flowering(),
        new Monkeys(),
        new Animals(),
        new Worms(),
        new Worms(),
        new Human(),
        new Monkeys(),
        new Mammals(),
        new Animals(),
        new Animals()
    };

    Animals* lf_lst[] {
        (Animals*)life[3], 
        (Animals*)life[4],
        (Animals*)life[5],
        (Animals*)life[6],
        (Animals*)life[7],
        (Animals*)life[8],
        (Animals*)life[9],
        (Animals*)life[10],
        (Animals*)life[11],
    };

    Monkeys* lf_lst2[] {
        (Monkeys*)life[3],
        (Monkeys*)life[8]
    };

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    for(int i = 0; i < 12; i++) delete life[i];

    return 0;
}