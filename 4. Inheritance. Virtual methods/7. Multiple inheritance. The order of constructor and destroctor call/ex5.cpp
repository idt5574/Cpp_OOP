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

class RetriveMixin {
    request_method method{ method_get };
public:
    RetriveMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~RetriveMixin() { }
    std::string get(const Request& request) { return "GET: " + request.url; }
};

class CreateMixin {
    request_method method{ method_post };
public:
    CreateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~CreateMixin() { }
    std::string post(const Request& request) { return "POST: " + request.url; }
};

class UpdateMixin {
    request_method method{ method_put };
public:
    UpdateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~UpdateMixin() { }
    std::string put(const Request& request) { return "PUT: " + request.url; }
};

class GeneralView : public RetriveMixin, public CreateMixin
{
    enum { max_methods = 4 };
    int count_methods{ 0 };
    request_method allowed_methods[max_methods]{ method_get, method_post };

    bool is_method_exist(request_method method)
    {
        for(int i = 0; i < max_methods; i++)
            if(allowed_methods[i] == method)
                return true;

        return false;
    }

public:

    GeneralView() : 
    RetriveMixin(new request_method{method_get}, 1), CreateMixin(new request_method(method_get), 1) {}

    std::string render_request(const Request& request)
    {
        if(is_method_exist(request.method)) return request.url;
        return "";
    }
};

int main(void)
{
    GeneralView gw;
    Request req {method_post, "https://proproprogs.ru/cpp_oop/cpp-oop-mnozhestvennoe-nasledovanie-poryadok-vyzova-konstruktorov-i-destruktorov", "<h1>Множественное наследование</h1>"};

    std::string res = gw.render_request(req);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}