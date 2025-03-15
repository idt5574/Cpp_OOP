#include <iostream>
#include <string>

class Employee
{
public:
    virtual const std::string& get_fname() const = 0;
    virtual const std::string& get_lname() const = 0;
    virtual short get_old() const = 0;
};

class Lector : public Employee
{
    std::string first_name, last_name;
    short old {0};
    int salary {0};

public:

    Lector(const std::string& first_name, const std::string& last_name, short old, int salary = 0)
    : first_name(first_name), last_name(last_name), old(old), salary(salary) {}

    virtual const std::string& get_fname() const override
    { return first_name; }

    virtual const std::string& get_lname() const override
    { return last_name; }

    virtual short get_old() const override
    { return old; }

    int get_salary() const
    { return salary; }

    void set_salary(int salary)
    { this->salary = salary; }

};

class Laborant : public Employee
{    
    std::string first_name, last_name, job_title;
    short old {0};
    

public:

    Laborant(const std::string& first_name, const std::string& last_name, short old, const std::string& job_title = "")
    : first_name(first_name), last_name(last_name), old(old), job_title(job_title) {}

    virtual const std::string& get_fname() const override
    { return first_name; }

    virtual const std::string& get_lname() const override
    { return last_name; }

    virtual short get_old() const override
    { return old; }

    const std::string& get_job_title() const
    { return job_title; }

    void set_job_title(const std::string& job_title)
    { this->job_title = job_title; }

};

enum { max_persons = 255 };

int main()
{
    Employee* staff[max_persons] {
        new Lector{"Sergey", "Balakirev", 33, 85000},
        new Laborant{"Elena", "Pozdnjakova", 27, "Programmer"},
        new Lector{"Olga", "Levkina", 38, 120000}
    };

    //__ASSERT_TESTS__

    for(int i = 0; i < 3; i++)
    {
        std::cout << staff[i]->get_fname() << ' ';
        delete staff[i];
    }

    std::cout << std::endl;

    return 0;
}