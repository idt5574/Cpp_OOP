#include <iostream>

class Clock
{
protected:
    unsigned time_current {0};

public:

    Clock() = default;
    Clock(unsigned tm) : time_current(tm) {}

    void set_time(unsigned tm) { time_current = tm; }
    unsigned get_hours() const { return time_current / 3600; }
    unsigned get_minutes() const {
        unsigned times=time_current - get_hours()*3600;
        return times / 60;
    }

    unsigned get_seconds() const {
        unsigned times = time_current - get_hours() * 3600;
        unsigned timest = times - get_minutes() * 60;
        return timest;
    }
};

class ClockShow : public Clock
{   
public:

    enum time_format { 
        tm_hhmmss=1,
        tm_hms,
        tm_ssmmhh,
        tm_smh
    };

private:
    time_format format {tm_hhmmss};

public:

    ClockShow() = default;
    ClockShow(unsigned time_current) : Clock(time_current) {}
    ClockShow(unsigned time_current, time_format format) : format(format), Clock(time_current) {}

    void show_time() const;
};

int main()
{
    unsigned time_current {7576};

    ClockShow clock {time_current, ClockShow::tm_hms};
    clock.show_time();

    return 0;
}

void ClockShow::show_time() const
{
    unsigned ss = get_seconds(),
        mm = get_minutes(),
        hh = get_hours();
    
    switch (format)
    {
    case tm_hhmmss:
        printf("%02d:%02d:%02d", hh, mm, ss);
        break;
    
    case tm_hms:
        printf("%d:%d:%d", hh, mm, ss);
        break;

    case tm_ssmmhh:
        printf("%02d:%02d:%02d", ss, mm, hh);
        break;

    case tm_smh:
        printf("%d:%d:%d", ss, mm, hh);
        break;
    }
}