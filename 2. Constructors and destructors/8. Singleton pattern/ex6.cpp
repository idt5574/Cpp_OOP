#include <iostream>

class Student {
    std::string fio;
    short old;

public:

    Student(const Student&) = delete;
    const Student operator=(const Student&) = delete;

    Student(const char* fio, short old) : fio(fio), old(old)
        {}

    void set_data(const std::string&, short); // заносит в соответствующие поля переданные значения
    std::string& get_fio() { return fio; } // возвращает значение поля fio
    short get_old() { return old; } // возвращает значение поля old
};

void Student::set_data(const std::string& fio, short old)
{
    this->fio = fio;
    this->old = old;
}

int main()
{
    Student *ptr_st = new Student("Pushkin", 21);

    // __ASSERT_TESTS__

    delete ptr_st;

    return 0;
}