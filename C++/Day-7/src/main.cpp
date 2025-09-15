#include <iostream>
#include <string>
#include <memory>

class BClass;

class AClass
{
    public:
    AClass(int a) : m_i{a}
    {
        std::cout << "A Constructor" << std::endl;
    }

    ~AClass()
    {
        std::cout << "A Destructor" << std::endl;
    }

    void SetRef(std::shared_ptr<BClass> b)
    {
        m_b = b;
    }

    private:
    int m_i;
    std::shared_ptr<BClass> m_b;
};

class BClass
{
    public:
    BClass(int a) : m_i{a}
    {
        std::cout << "B Constructor" << std::endl;
    }

    ~BClass()
    {
        std::cout << "B Destructor" << std::endl;
    }

    void SetRef(std::shared_ptr<AClass> a)
    {
        m_a = a;

        if(std::shared_ptr temp = m_a.lock())
        {
            //...
        }
        
    }

    private:
    int m_i;
    std::weak_ptr<AClass> m_a;
};

AClass* Foo()
{
    std::shared_ptr a = std::make_shared<AClass>(5);
    std::shared_ptr b = std::make_shared<BClass>(20);

    return a.get();
}

int main()
{
    std::cout << "End of Main" << std::endl;
}
