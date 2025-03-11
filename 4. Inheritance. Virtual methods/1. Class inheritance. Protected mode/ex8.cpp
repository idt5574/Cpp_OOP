#include <iostream>

class Wallet
{
    int volume {0};

    bool check_volume(int x) { return x >= 0; }

public:

    Wallet() = delete;
    Wallet(int volume) : volume(volume) {}

    void add(int vol) { volume += check_volume(vol) ? vol : 0; }
    int get_volume() const { return volume; }

};

int main()
{

    Wallet wallet {544653};

    int vl = wallet.get_volume();

    // __ASSERT_TESTS__

    return 0;
}