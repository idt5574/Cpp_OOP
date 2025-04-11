#include <iostream>
#include <string>

class ClockError : public std::exception
{
protected: 
    std::string msg;

public:

    ClockError(const std::string error) noexcept : msg(error)
    {}

    const char * what() const noexcept override 
    {
        return msg.data();
    }

    virtual ~ClockError() {}
};

class ClockValueError : public ClockError
{
public:

    ClockValueError(const std::string error) noexcept : ClockError(error) 
    {}

    ~ClockValueError() {}

};

class ClockIndexError : public ClockError
{
public:

    ClockIndexError(const std::string error) noexcept : ClockError(error)
    {}

    ~ClockIndexError() {}

};

using uint8 = unsigned char;

class Clock {
    uint8 hours {0};
    uint8 mins {0};
    uint8 secs {0};

    class Item {
        Clock* current {nullptr};
        int index {-1};

    public:
        Item(Clock* obj, int indx) : current{obj}
        { 
            if(indx < 0 || indx > 2)
                throw ClockIndexError("Clock: index error");

            index = indx;
        }

        uint8 operator=(uint8 right)
        {
            if((index == 0 && (right < 0 || right > 11)) || 
                ((index == 1 || index == 2) && (right < 0 || right > 59)))
                throw ClockValueError("Clock: out of range");

            switch(index) {
                case 0: current->hours = right; break;
                case 1: current->mins = right; break;
                case 2: current->secs = right; break;
            }
            return right;
        }
        operator uint8() const
        {
            switch(index) {
                case 0: return current->hours;
                case 1: return current->mins;
                case 2: return current->secs;
            }
            return 0;
        }
    };

public:
    Clock(uint8 hs = 0, uint8 ms = 0, uint8 sc = 0)
    { 
        if(hs < 0 || hs > 11 || ms < 0 || ms > 59 || sc < 0 || sc > 59)
            throw ClockValueError("Clock: out of range");

        hours = hs;
        mins = ms;
        secs = sc;
    }
    unsigned get_time() const { return hours * 3600 + mins * 60 + secs; }
    void get_time(uint8& hours, uint8& mins, uint8& secs) const
    {
        hours = this->hours; mins = this->mins; secs = this->secs;
    }
    void set_time(uint8 hours, uint8 mins, uint8 secs)
    {
        if(hours < 0 || hours > 11 || mins < 0 || mins > 59 || secs < 0 || secs > 59)
            throw ClockValueError("Clock: out of range");

        this->hours = hours; this->mins = mins; this->secs = secs;
    }
    Item operator[](int indx) 
    {
        return Item(this, indx);
    }
};

int main()
{
    try
    {
        Clock cl {10, 19, 24};
    }
    catch(const ClockIndexError& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const ClockValueError& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const ClockError& e)
    {
        std::cout << e.what() << '\n';
    }
    

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}