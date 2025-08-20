#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <type_traits>
#include <string>
#include <stdio.h>

class string
{
    private:
    char* data;

    public:
    string()
    {
        data = new char[10];
    }

    const char* c_str()
    {
        return data;
    }
};

class Employee
{
    public:
    std::string first_name;
    std::string last_name;
    int years_of_experience;
    float salary;
    std::string salary_string;
    int age;
    
    Employee(std::string name)
    {
        first_name = name;
    }

    void PrintName()
    {
        std::cout << first_name << " " << last_name << std::endl;
    }

    void SetSalary(float s)
    {
        salary = s;
        salary_string = std::to_string(s) + "$";
    }
};

class Engineer : public Employee
{
    public:
    Engineer(std::string name) : Employee(name)
    {
        
    }

    std::string specialization;
};

class Cleaner : public Employee
{
    std::string building;
};

class Security : public Employee
{
    std::string gate;
};

void OldFunction(const char* c_string)
{

}

void PrintString(const std::string& s)
{
    std::cout << s << std::endl;

    OldFunction(s.c_str());
}

int main()
{
    const std::string str = "Hello";
    std::string_view sv = "Hello";

    PrintString(str);
}