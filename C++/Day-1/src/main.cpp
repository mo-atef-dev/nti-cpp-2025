#include "my_module.h"
#include <iostream>
#include <vector>

enum class Car {BMW, Mercedes, KIA};

void print_car(Car c)
{
    using enum Car;

    switch(c)
    {
        case Car::BMW:
        std::cout << "BMW" << std::endl;
        break;
        case Car::Mercedes:
        std::cout << "Mercedes" << std::endl;
        break;
        case Car::KIA:
        std::cout << "KIA" << std::endl;
        break;
    }
}

int main()
{
    Car car = Car::BMW;

    print_car(car);
    my_print();

    return 0;
}