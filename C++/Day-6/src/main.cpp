#include <iostream>
#include "my_array.h"
#include <string>

#include <memory>

class A
{
    public:
    A(int num = 3) : m_num{num}
    {
        std::cout << "Constructor called" << std::endl;
    }

    void Print()
    {
        std::cout << "Hello from A " << m_num << std::endl;
    }

    ~A()
    {
        std::cout << "Destructor called" << std::endl;
    }
    
    private:
    int m_num;
};



std::unique_ptr<A> Foo()
{
    std::cout << "Foo called" << std::endl;
    
    std::unique_ptr<A> a{new A{5}};

    (*a).Print();
    
    std::cout << "End of foo" << std::endl;

    return a;
}

int main()
{
    std::unique_ptr<A> b = Foo();
    std::unique_ptr<A> c = std::move(b);

    if(b)
    {
        std::cout << "b owns a resource" << std::endl;
        auto ptr_b = b.get();
        std::cout << ptr_b << std::endl;
    }

    
    auto ptr_c = c.get();
    std::cout << ptr_c << std::endl;

    b = Foo();
}
