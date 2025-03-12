#include <iostream>
#include <string>

enum request_method { // обрабатываемые методы
    method_get = 1,
    method_post = 2,
    method_put = 3,
    method_delete = 4
};

struct Request { // объект запроса
    request_method method {method_get};
    std::string url;
    std::string data;
};

class GenericView { // базовый класс для обработки запросов
protected:
    enum {total_methods = 3}; // количество обрабатываемых методов
    request_method methods[total_methods] = {method_get, method_post, method_put}; // массив допустимых методов
public:
    virtual std::string get(const Request& request) 
    {
        return request.data;
    }
    virtual std::string post(const Request& request) 
    {
        return request.data;
    }
    virtual std::string put(const Request& request) 
    {
        return request.data;
    }
    virtual std::string del(const Request& request) 
    {
        return request.data;
    }
};

class DetailView : public GenericView
{
    bool is_method_exist(request_method method)
    {
        for(int i = 0; i < 3; i++)
        {
            if(methods[i] == method)
                return true;
        }

        return false;
    }

public:

    std::string get(const Request& request)
    { return request.url; }

    const std::string render_request(const Request& request)
    {
        if(!is_method_exist(request.method)) return "";

        switch (request.method)
        {
        case method_get:
            return get(request);

        case method_post:
            return post(request);

        case method_put:
            return put(request);

        case method_delete:
            return del(request);
        
        default:
            break;
        }
    }
};

int main(void)
{
    DetailView dw;

    std::string res = dw.render_request((Request){method_get, "https://proproprogs.ru/cpp_oop/cpp-oop-virtualnye-virtual-metody-funkcii", "<h1>Заголовок</h1>"});

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}