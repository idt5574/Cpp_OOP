#include <iostream>
#include <string>

using std::string;

class Printer
{
public: 

    enum type_printer { 
        pr_none=0,
        pr_needle=1,
        pr_jet=2,
        pr_laser=3
    };

protected:

    string model;
    type_printer type {pr_none};

public:

    Printer() = delete;
    Printer(const string& model, type_printer type)
    : model(model), type(type) {}

    const string& get_model() const
    { return model; }

    type_printer get_type() const
    { return type; }

};

class PrinterJet : public Printer
{
    bool color {false};
    short speed {0};

public:

    PrinterJet(const string model, bool color, short speed)
    : Printer(model, pr_jet), color(color), speed(speed) {}

    void get_data(string& model, type_printer& type, bool& color, short& speed)
    { model = this->model; type = this->type; color = this->color; speed = this->speed; }

};

class PrinterLaser : public Printer
{
    bool color {false};
    short speed {0};

public:

    PrinterLaser(const string model, bool color, short speed)
    : Printer(model, pr_laser), color(color), speed(speed) {}

    void get_data(string& model, type_printer& type, bool& color, short& speed)
    { model = this->model; type = this->type; color = this->color; speed = this->speed; }
   
};

int main()
{
    Printer* pr_lst[4] {
        new PrinterJet{"Brother Jet 600", true, 5},
        new PrinterLaser{"Canon Laser 10", false, 10},
        new PrinterJet{"Samsung Jet 100", true, 7},
        new PrinterLaser{"BaLaser 1 Pro", true, 21}
    };

    // __ASSERT_TESTS__

    for(int i = 0; i < 4; i++) delete pr_lst[i];

    return 0;
};