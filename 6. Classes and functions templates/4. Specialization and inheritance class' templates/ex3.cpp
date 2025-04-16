#include <iostream>
#include <cstring>

template <typename T1, typename T2>
class Thing {
    static T1 acc_uid;
    T1 uid {0};
    T2 name;
    int price {0};
    double weight {0.0};
public:
    Thing(T2 name, int price, double weight) : name(name), price(price), weight(weight)
    {
        uid = acc_uid++;
    }

    T1 get_uid() const { return uid; }
    T2 get_name() const { return name; }
    void get_data(int& price, double& weight) { price = this->price; weight = this->weight; }
};

template <typename T1>
class Thing<T1, char*> {
    static T1 acc_uid;
    T1 uid {0};
    char name[100] {0};
    int price {0};
    double weight {0.0};
public:
    Thing(const char* name, int price, double weight) : price(price), weight(weight)
    {
        strncpy(this->name, name, (strlen(name) > 100 ? 100 : strlen(name)));
        uid = acc_uid++;
    }

    T1 get_uid() const { return uid; }
    const char* get_name() const { return name; }
    void get_data(int& price, double& weight) { price = this->price; weight = this->weight; }
};

template <typename T1, typename T2>
T1 Thing<T1, T2>::acc_uid = 0;

template <typename T1>
T1 Thing<T1, char*>::acc_uid = 0;

int main()
{
    Thing<int, char*> th {"Templates in C++", 2000, 0.13}; 
    
    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}