#include <iostream>

class TravelBlog
{
    std::string country;
    short days;

public:

    void set_info(const std::string &country, short days)
    {
        this->country = country;
        this->days = days;
    }

    void set_info(const TravelBlog& blog)
    {
        country = blog.country;
        days = blog.days;
    }

    const std::string& get_country()
        { return country; }
    
    short get_days()
        { return days; }

};

int main()
{
    TravelBlog blog1, blog2;

    blog1.set_info("ОАЭ", 10);
    
    blog2.set_info(blog1);

    // __ASSERT_TESTS__
    return 0;
}