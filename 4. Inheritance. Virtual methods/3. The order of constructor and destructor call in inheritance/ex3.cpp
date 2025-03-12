#include <iostream>
#include <string>

class SmartPhone
{
protected:

    std::string model;
    double weight {0};

public:

    SmartPhone() : model("default_phone"), weight(0) {}
    SmartPhone(const std::string& model, double weight)
    : model(model), weight(weight) {}

    const std::string& get_model() const
    { return model; }

    double get_weight() const
    { return weight; }

};

class IPhone : public SmartPhone
{
    int memory_volume {0};
    int display_size {0};

public:

    IPhone(const std::string& model, double weight, int memory_vol, int display_sz)
    : SmartPhone(model, weight), memory_volume(memory_vol), display_size(display_sz) {}

    void get_info(int& memory, int& size)
    { memory = memory_volume; size = display_size; }

};

int main()
{
    IPhone iPhone12 {"iPhone12", 0.17, 64000, 11};

    // __ASSERT_TESTS__

    return 0;
};

