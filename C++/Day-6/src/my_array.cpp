#include "my_array.h"
#include <iostream>

array::array(int size) : m_arr(size)
{
    for(int i = 0; i < size; i++)
    {
        m_arr[i] = 0;
    }
}

array::array(const array& arr) : m_arr{arr.m_size}
{
    m_size = arr.m_size;

    for(int i = 0; i < m_size; i++)
    {
        m_arr[i] = 0;
    }
}

int array::Read(int index)
{
    // Bound check
    if(index < 0 || index >= m_size)
    {
        std::cout << "Error: Out of bounds access" << std::endl;
        return -1;
    }
    
    // Return the value
    return m_arr[index];
}

void array::Write(int index, int value)
{
    // Bound check
    if(index < 0 || index >= m_size)
    {
        std::cout << "Error: Out of bounds access" << std::endl;
        return;
    }

    m_arr[index] = value;
}

int array::GetSize()
{
    return m_size;
}