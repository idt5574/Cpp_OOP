#include <iostream>

class Object {
protected:
    int x{0}, y{0};
    int speed {0};
public:
    Object(int x = 0, int y = 0, int speed = 0) : x(x), y(y), speed(speed)
        { }
    virtual ~Object() { }

    void set_speed(int speed) { this->speed = speed; }
    int get_speed() const { return speed; }
    int get_x() const { return x; }
    int get_y() const { return y; }
};

class ObjectFly : virtual public Object
{
protected:

    int z {0}; // высота полета (3-я координата)
    double angle {0.0}; // направление полета

public:

    ObjectFly(int z = 0, double angle = 0)
    : Object(), z(z), angle(angle) {}

    virtual ~ObjectFly() {}

    int get_z() const
    { return z; } // возвращает значение координаты z

    double get_angle() const
    { return angle; } // возвращает значение угла angle

    void set_angle(double angle)
    { this->angle = angle; } // устанавливает значение угла angle

};

class ObjectOperators : virtual public Object
{
public:

    ObjectOperators(int x = 0, int y = 0, int speed = 0)
    : Object(x, y, speed) {}

    virtual ~ObjectOperators() {}

    void operator+=(int delta)
    { speed += delta; } // увеличивает значение скорости на delta

    void operator-=(int delta)
    { speed -= delta; } // уменьшает значение скорости на delta
    
};

class Plane : public ObjectOperators, public ObjectFly
{
public:

    Plane(int x = 0, int y = 0, int z = 0) 
    : Object(x, y), ObjectFly(z) {}

    virtual ~Plane() {};

};

int main(void)
{
    Plane pl(20, 43, 100);

    pl.set_speed(10);
    pl += 5;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}