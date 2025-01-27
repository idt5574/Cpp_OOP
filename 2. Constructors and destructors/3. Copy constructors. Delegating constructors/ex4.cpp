#include <iostream>
#include <string>

class Person {
    std::string fio;
    short old {0};
    long salary {0};

public:

    Person(const std::string& fio) : fio(fio)
        { std::cout << "Person(string)" << std::endl; }
    
    Person(std::string fio, short old, long salary) : Person(fio)
    { 
        this->old = old;
        this->salary = salary;
    }

    void get_data(std::string& fio, short& old, long& salary)
    {
        fio = this->fio; old = this->old; salary = this->salary;
    }
};

int main(void)
{
    Person *ptr_p = new Person("Рахманинов С.В.", 75, 13204); 

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_p;

    return 0;
}