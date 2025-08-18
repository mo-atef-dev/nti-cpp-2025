#include <iostream>
#include "my_array.h"

int main()
{
    array a{20};
    array b{a};

    b = a;

    a.Write(12, 10);
    
    for(int i = 0; i < b.GetSize(); i++)
    {
        std::cout << b.Read(i) << std::endl;
    }
}