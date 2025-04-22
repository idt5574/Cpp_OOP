#include <iostream>
#include <string>
#include <memory>

class LinkedListIndexError : public std::exception
{
    std::string msg;

public:

    LinkedListIndexError(const std::string& error) : msg(error) {}

    const char * what() const noexcept override { return msg.c_str(); }

    ~LinkedListIndexError() {}

};

template <typename T>
class Object
{
    T data {0};
    std::shared_ptr<Object<T>> next {nullptr};

public:

    Object(T data) : data(data) {}
    Object(T data, std::shared_ptr<Object<T>> next) : data(data), next(next) {}

    T get_data() const
    {
        return data;
    }

    std::shared_ptr<Object<T>> get_next() const
    {
        return next;
    }

    void set_next(std::shared_ptr<Object<T>> new_next)
    {
        next = new_next;
    }

    T& get_data()
    {
        return data;
    }

    operator T() const
    {
        return data;
    }

};

template <typename T>
using shared_obj = std::shared_ptr<Object<T>>;

template <typename D>
class OneLinkedList
{
    shared_obj<D> head {nullptr};
    shared_obj<D> tail {nullptr};

    unsigned length {0};

public:

    OneLinkedList() = default;

    void push_front(const D& data) // Добавление элемента в начало списка
    {
        shared_obj<D> new_node = std::make_shared<Object<D>>(data); // Новая нода (создаётся указатель и сразу привязывается к объекту new_node)

        new_node->set_next(head); // Сразу присваиваем голову списка следующей для новой ноды

        head = new_node; // Заменяем указатель головы на новую ноду

        if(length == 0)
            tail = head;

        new_node.reset(); // Отвязываем новую ноду от созданного объекта

        length++;
    }

    void push_back(const D& data) // Добавление элемента в конец списка
    {
        shared_obj<D> new_object = std::make_shared<Object<D>>(data); // Новая нода (создаётся указатель и сразу привязывается к объекту new_node)

        if(head == nullptr)
        { // Если головы не существует, сразу привязываем к ней новый указатель
            head = new_object;
            tail = head;
        }
        else
        {
            tail->set_next(new_object); // Новую ноду ставим следующим элементом для хвоста   
            tail = new_object; // Перепривязываем объект хвоста к новой ноде
        }

        new_object.reset(); // Отвязываем новую ноду от созданного объекта

        length++;
    }

    shared_obj<D> pop_back() // Удаление объекта с конца
    {
        if(head == nullptr) // Если голова имеет нулевой указатель - ничего не делаем
            return nullptr;
        
        if(head->get_next() == nullptr) {
            head.reset();
            tail.reset();
            length = 0;
            return nullptr;
        }

        shared_obj<D> curr = tail; // Привязываем к curr предыдущий для хвоста указатель
        if (tail != nullptr) {
            tail->set_next(nullptr);
        } else {
            head.reset();
        }

        curr.reset(); // Отвязываем указатель от созданного объекта

        length--;

        return head;
    }

    shared_obj<D> pop_front() // Удаление объекта из начала
    {        
        if(head == nullptr)
        {
            return nullptr;
        }
        
        shared_obj<D> temp = head;
        head = head->get_next();
        
        if(head == nullptr) 
            tail.reset();
        
        temp.reset();
        length--;
        
        return head;
    }

    D& operator[] (unsigned index)
    {

        if(index >= length)
            throw LinkedListIndexError("Invalid element index.");

        shared_obj<D> curr = head;

        for(int i = 0; curr != nullptr && i != index; i++, curr = curr->get_next());

        return curr.get()->get_data();
    }

    shared_obj<D>& get_head()
    {
        return head;    
    }

    shared_obj<D>& get_tail()
    {
        return tail;    
    }
};

struct Complex
{
    int x, y;

    Complex(int x, int y) : x(x), y(y) {}
};

int main()
{
    OneLinkedList<int> lst1;

    OneLinkedList<Complex> lst2; // пустой односвязный список для хранения данных типа Complex (структура)

    lst2.push_back(Complex {1, 2}); // добавление в конец списка
    lst2.push_back(Complex {3, 4}); // добавление в конец списка
    lst2.push_front(Complex {-1, -2}); // добавление в начало списка
    lst2.pop_back(); // удаление последнего элемента (если его нет, то ничего не делать)
    lst2.pop_front(); // удаление первого элемента (если его нет, то ничего не делать)
    
    Complex d = lst2[0];  // получение первого элемента по индексу
    lst2[0] = Complex {5, 8}; // запись в первый элемент по индексу
    
    OneLinkedList<int> lst_int; // еще один односвязный список для хранения данных типа int
    
    lst_int.push_back(1); // добавление в конец списка
    lst_int.push_back(2);
    lst_int.push_back(3);
    
    int var = lst_int[1]; // чтение данных из второго элемента списка
    lst_int[2] = -5; // запись данных в третий элемент списка
    
    // перебор первого списка
    std::shared_ptr< Object<Complex> > ptr_lst = lst2.get_head();
    while(ptr_lst) {
        Complex res = ptr_lst->get_data();
        ptr_lst = ptr_lst->get_next();
    }
    
    // перебор второго списка
    std::shared_ptr< Object<int> > ptr_lst_int = lst_int.get_head();
    while(ptr_lst_int) {
        int a = ptr_lst_int->get_data();
        ptr_lst_int = ptr_lst_int->get_next();
    }

    return 0;
}