#include "my_array.h"
#include <iostream>

array::array(int size)
{
    m_arr = new int[size];

    for(int i = 0; i < size; i++)
    {
        m_arr[i] = 0;
    }

    m_size = size;
}

array::array(const array &source)
{
    m_size = source.m_size;
    m_arr = new int[source.m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_arr[i] = source.m_arr[i];
    }
}

array::~array()
{
    delete[] m_arr;
}

array& array::operator=(const array& source)
{
    /* Check if I am assigning myself */
    if(&source == this)
        return *this;

    delete[] m_arr;
    m_size = source.m_size;
    m_arr = new int[source.m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_arr[i] = source.m_arr[i];
    }

    return *this;
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