#include <iostream>

class Notebook
{
    std::string model{"-"};
    std::string cpu_model{"-"};
    unsigned memory {0};
    unsigned disk_volume {0};

public:

    Notebook(const char* model) : model(model)
        { }

    Notebook(std::string model="-", std::string cpu_model="-", unsigned memory=0, unsigned disk_volume=0)
        : model(model), cpu_model(cpu_model), memory(memory), disk_volume(disk_volume)
        { }

    void set_data(const std::string& model, const std::string& cpu, unsigned memory, unsigned disk)
    {
        this->model = model;
        cpu_model = cpu;
        this->memory = memory;
        this->disk_volume = disk;
    }

    std::string& get_model()
        { return model; }
    
    std::string& get_cpu()
        { return cpu_model; }
    
    void get_info(unsigned& memory, unsigned& disk_volume)
    {
        memory = this->memory;
        disk_volume = this->disk_volume;
    }
};

int main()
{
    Notebook note{"HP", "Core i7", 16000, 512};

    // __ASSERT_TESTS__

    return 0;
}