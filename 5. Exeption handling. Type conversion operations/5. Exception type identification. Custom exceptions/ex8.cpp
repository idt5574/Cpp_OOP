#include <iostream>

class ColorRGBError : public std::exception
{
protected:
    std::string msg;

public:

    ColorRGBError(const std::string& error) : msg(error) {}

    const char * what() const noexcept override { return msg.c_str(); }

    virtual ~ColorRGBError() {}
};

class ColorRGBValueError : public ColorRGBError
{
public:

    ColorRGBValueError(const std::string& error) : ColorRGBError(error) {}

    ~ColorRGBValueError() {}
};

class ColorRGBIndexError : public ColorRGBError
{
public:

    ColorRGBIndexError(const std::string& error) : ColorRGBError(error) {}

    ~ColorRGBIndexError() {}
};

class ColorRGB
{
    short r{0}, g{0}, b{0};

    static void ValidateValue(short a)
    {
        if(a < 0 || a > 255)
            throw ColorRGBValueError("Valid values must be in the range [0; 255]");
    }

    static void ValidateIndex(int index)
    {
        if(index < 0 || index > 2)
            throw ColorRGBIndexError("Index must be in range [0; 2]");
    }

    class Item
    {
        ColorRGB* current {nullptr};
        int index {-1};

    public:
        Item(ColorRGB* object, int index)
        {
            ValidateIndex(index);

            current = object;
            this->index = index;
        }

        operator short() const
        {
            switch (index)
            {
            case 0:
                return current->r;
            case 1:
                return current->g;
            case 2:
                return current->b;
            }
        }

        void operator = (short other)
        {
            ValidateValue(other);

            switch (index)
            {
            case 0:
                current->r = other;
                return;
            case 1:
                current->g = other;
                return;
            case 2:
                current->b = other;
                return;
            }
        }
    };

public:

    ColorRGB() = default;
    ColorRGB(short r, short g, short b)
    {
        ValidateValue(r);
        ValidateValue(g);
        ValidateValue(b);

        this->r = r; this->g = g; this->b = b;
    }

    Item operator [] (int index)
    {
        return Item(this, index);
    }

    void set_rgb(short r, short g, short b)
    {
        ValidateValue(r);
        ValidateValue(g);
        ValidateValue(b);

        this->r = r; this->g = g; this->b = b;
    }

};

int main()
{
    try
    {
        ColorRGB yellow {255, 201, -14};
    }
    catch(const ColorRGBValueError& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const ColorRGBIndexError& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const ColorRGBError& e)
    {
        std::cout << e.what() << '\n';
    }
    
    // __ASSERT_TESTS__

    return 0;
}
