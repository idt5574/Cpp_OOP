#include <iostream>
#include <memory>

template <typename T>
class Object {
    T data {0};
    std::shared_ptr<Object> next {nullptr};
public:
    Object(T d) : data(d), next(nullptr)
        { }

    T get_data() const { return data; }
    std::shared_ptr<Object>& get_next() { return next; }
};

template <typename T>
using shared_obj_ptr = std::shared_ptr<Object<T>>;

template <typename D>
class Stack {
    shared_obj_ptr<D> top {nullptr};
public:
    shared_obj_ptr<D> get_top() { return top; }

    void push(D data)
    {
        shared_obj_ptr<D> node = std::make_shared<Object<D>>(data);
        node->get_next() = top;
        top = node;
    }

    shared_obj_ptr<D> pop() {
        if (!top) return nullptr;
        shared_obj_ptr<D> ptr = top;
        top = top->get_next();
        return ptr;
    }
};
