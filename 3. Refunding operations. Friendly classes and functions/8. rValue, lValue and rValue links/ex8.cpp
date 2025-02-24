#include <iostream>

class Distance
{
    int dist {0};

public:

    Distance() = default;
    Distance(int d) : dist(d) {}

    const Distance& operator=(const Distance& other)
    {
        if(this == &other) return *this;
        dist = other.dist;
        return *this;
    }

    const Distance operator+=(const Distance& other)
    {
        dist += other.dist;
        return *this;
    }

    const Distance& operator-=(const Distance& other)
    {
        dist -= other.dist;
        return *this;
    }

    const Distance& operator*=(const Distance& other)
    {
        dist *= other.dist;
        return *this;
    }

    const Distance& operator/=(const Distance& other)
    {
        dist /= other.dist;
        return *this;
    }

    int operator() ()
    { return dist; }
};

int main()
{
    Distance obj {547};

    Distance& lnk_d {obj};
    Distance&& lnk_r_d {std::move(obj)};

    lnk_r_d += 100;

    // __ASSERT_TESTS__

    return 0;
}