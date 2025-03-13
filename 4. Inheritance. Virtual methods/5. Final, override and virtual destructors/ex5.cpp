#include <iostream>
#include <string>

class Art
{
protected:
    short stars {0};

public:

    Art(short st = 0) : stars(st) {}

    virtual void set_stars(short vol) 
    { stars = vol; }

    short get_stars() const { return stars; }

    virtual ~Art() {}

};

class Painting : public Art
{
    std::string title, author;

public:

    Painting(const std::string& title, const std::string& author)
    : Art(), title(title), author(author) {}

    const std::string& get_title() const
    { return title; }

    const std::string& get_author() const
    { return author; }

    virtual ~Painting() 
    { puts("~Painting"); }

};

class Music : public Art
{
    std::string title, composer;
    int max_stars {5};

public:

    Music(const std::string& title, const std::string composer)
    : Art(), title(title), composer(composer) {}

    const std::string& get_title() const
    { return title; }

    const std::string& get_composer() const
    { return composer; }

    virtual void set_stars(short vol) override
    { stars = (vol > max_stars ? max_stars : vol); }

    virtual ~Music()
    { puts("~Music"); }

};