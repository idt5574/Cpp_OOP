#include <iostream>

class PhysicInterface {
public:
    virtual void forward(int speed) = 0; // движение вперед
    virtual void stop() = 0; // останов
    virtual void left(double angle) = 0; // поворот влево
    virtual void right(double angle) = 0; // поворот вправо

    virtual ~PhysicInterface() { }
};

class Car
{
protected:

    int speed {0};
    int x {0}, y {0};
    int weight {0};
    double angle {0.0};

public:

    Car(int x, int y, int weight)
    : x(x), y(y), weight(weight) {}

    void get_coords(int& x, int& y) const
    { x = this->x; y = this->y; }

    int get_speed() const
    { return speed; }

    int get_weight() const
    { return weight; }

    double get_angle() const
    { return angle; }

};

class Train
{
protected:

    int speed {0};
    int x {0}, y {0};
    int weight {0};
    double power {0.0};

public:

    Train(int x, int y, int weight, double power)
    : x(x), y(y), weight(weight), power(power) {}

    void get_coords(int& x, int& y) const
    { x = this->x; y = this->y; }

    int get_speed() const
    { return speed; }

    int get_weight() const
    { return weight; }
 
    double get_power() const
    { return power; }

};

class ModelCar : public Car, public PhysicInterface
{
public:

    ModelCar(int x, int y, int weight)
    : Car(x, y, weight) {}

    virtual void forward(int speed) override
    { this->speed = speed; } // заносит значение speed в поле speed

    virtual void stop() override
    { this->speed = 0; } // устанавливает значение speed равным 0

    virtual void left(double angle) override
    { this->angle = angle; } // ничего не делает (пустое тело)

    virtual void right(double angle) override
    { this->angle = -angle; } // ничего не делает (пустое тело) 
};

class ModelTrain : public Train, public PhysicInterface
{
public:

    ModelTrain(int x, int y, int weight, double power)
    : Train(x, y, weight, power) {}

    virtual void forward(int speed) override
    { this->speed = speed; } // заносит значение speed в поле speed

    virtual void stop() override
    { speed = 0; } // устанавливает значение speed равным 0

    virtual void left(double angle) override
    {} // ничего не делает (пустое тело)

    virtual void right(double angle) override
    {} // ничего не делает (пустое тело)
};

int main(void)
{
    PhysicInterface* obj_lst[4] {
        new ModelCar{0, 0, 1200},
        new ModelTrain{-5, 7, 534200, 574.33},
        new ModelCar{11, 24, 1920},
        new ModelCar{-1, 12, 945}
    };

    for(int i = 0; i < 4; i++)
        obj_lst[i]->forward(7);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    for(int i = 0; i < 4; i++)
    {
        delete obj_lst[i];
    }

    return 0;
}