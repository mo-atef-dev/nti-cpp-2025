#include <iostream>
#include <string>
#include <exception>

class AbstractRepository
{
    public:
    virtual void SaveData(std::string data) = 0;

    void ReadData(int id)
    {

    }

    virtual ~AbstractRepository()
    {
        std::cout << "Abstract repo destructor" << std::endl;
    }
};

class FileSystemRepository : public AbstractRepository
{
    public:
    void SaveData(std::string data) override
    {
        std::cout << "Filesystem repository" << std::endl;
    }

    void ReadData(int id)
    {

    }
};

class MsSqlRepository : public AbstractRepository
{
    private:
    double* ptr;

    public:
    void SaveData(std::string data) override
    {
        std::cout << "MsSQL repository" << std::endl;
        ptr = new double[100];
    }

    void ReadData(int id)
    {

    }

    ~MsSqlRepository() override
    {
        std::cout << "MsSQL destructor" << std::endl;
        delete ptr;
    }
};

class RemoteHttpRepository : public AbstractRepository
{
    public:
    void SaveData(std::string data) override
    {
        std::cout << "Http repository" << std::endl;
    }

    void ReadData(int id)
    {

    }
};

int main()
{
    AbstractRepository* repo = new MsSqlRepository();

    //...

    delete repo;
}