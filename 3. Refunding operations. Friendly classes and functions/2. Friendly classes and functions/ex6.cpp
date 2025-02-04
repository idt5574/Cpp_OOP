#include <iostream>

class Distance {
    long dist {0};

public:
    Distance(long dist=0) : dist(dist)
        { }

    friend void set_distance(Distance&, long); // заносит в поле dist объекта dst значение value
    friend long get_distance(const Distance&); // возвращает значение поля dist объекта dst
    friend double distance_to_meters(const Distance&); // возвращает значение поля dist объекта dst в метрах
    friend Distance operator +(const Distance&, const Distance&);
};

void set_distance(Distance& dst, long value) {
    dst.dist = value;
}

long get_distance(const Distance& dst) {
    return dst.dist;
}

double distance_to_meters(const Distance& dst) {
    return (double)dst.dist / 1000.00;
}

Distance operator +(const Distance& left, const Distance& right) {
    return Distance(left.dist + right.dist);
}

int main()
{
    Distance d{783};

    printf("%d %.2f\n", get_distance(d),distance_to_meters(d));

    // __ASSERT_TESTS__

    return 0;
}