#include <iostream>
#include <cstring>

class IntOperator
{
    int* data {nullptr};
    int size {0};

public:
    
    IntOperator()
        {}
    
    IntOperator(int* data, int size)
    {
        this->size = size;
        this->data = data;
    }

    ~IntOperator()
    { 
        for(int i = 0; i < size; i++)
            data[i] = 0;
    }

    double average();   
    int sum();
    int max();
    int min();

};

double IntOperator::average()
    { return (double)sum() / (double)size; }

int IntOperator::sum()
{
    int res = 0;

    for(int i = 0; i < size; i++)
        res += data[i];

    return res;
}

int IntOperator::max()
{
    int ma = -100000;

    for(int i = 0; i < size; i++)
        if(data[i] > ma) ma = data[i];

    return ma;        
}

int IntOperator::min()
{
    int mi = 100000;

    for(int i = 0; i < size; i++)
        if(data[i] < mi) mi = data[i];

    return mi;  
}

int main()
{
    int dt[] = {0, -5, 2, 10, 7, 22};
    int dt2[] = {1, 2, 10, -7, -5};

    IntOperator op_1;
    IntOperator op2(dt, std::size(dt)); // std::size() возвращает число элементов массива data (C++17)
    IntOperator op3(dt2, std::size(dt2));

    int mi2 = op2.min();
    int ma2 = op2.max();
    int su2 = op2.sum();
    double av2 = op2.average();

    int mi3 = op3.min();
    int ma3 = op3.max();
    int su3 = op3.sum();
    double av3 = op3.average();

    return 0;
}