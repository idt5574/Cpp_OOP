#include <iostream>

class Wallet {
    int volume {0};

    bool check_volume(int);

public:

    Wallet() = delete;
    Wallet(int volume) : volume(volume)
        { }

    void add(int);
    int get_volume();
};

bool Wallet::check_volume(int volume)
    { return volume >= 0; }

void Wallet::add(int volume)
{
    if(check_volume(volume))
        this->volume += volume;
}

int Wallet::get_volume()
    { return volume; }

int main()
{
    Wallet wallet(544653);
    int vl = wallet.get_volume();

    // __ASSERT_TESTS__

    return 0;
}