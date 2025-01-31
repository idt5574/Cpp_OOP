#include <iostream>

class DataThree {
    static unsigned count;
    static DataThree* last_instance;

    DataThree() = default;
    DataThree(const DataThree&) = delete;

public:
    static DataThree* get_new_data() {
        if (count < 3) {
            last_instance = new DataThree();
            ++count;
        }
        return last_instance;
    }
    
    ~DataThree() {
        --count;
        if (count == 0)
            last_instance = nullptr;
    }
};

unsigned DataThree::count{ 0 };
DataThree* DataThree::last_instance{ nullptr };

int main() {
    DataThree* ptr_dates[5];

    for (int i = 0; i < 5; ++i)
        ptr_dates[i] = DataThree::get_new_data();
    
    // __ASSERT_TESTS__

    return 0;
}