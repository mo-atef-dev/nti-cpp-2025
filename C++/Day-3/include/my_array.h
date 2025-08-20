#pragma once

#include <iostream>

template<typename T>
class array
{
    public:
    array() = delete;
    array(int size);
    array(const array& source);
    ~array();

    array& operator=(const array&);
    T& operator[](int index);

    auto x = a[5];
    a[5] = 3;

    int GetSize();

    private:
    T* m_arr;
    int m_size;
};

template<typename T>
array<T>::array(int size)
{
    m_arr = new T[size];

    m_size = size;
}

template<typename T>
array<T>::array(const array<T> &source)
{
    m_size = source.m_size;
    m_arr = new T[source.m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_arr[i] = source.m_arr[i];
    }
}

template<typename T>
array<T>::~array()
{
    delete[] m_arr;
}

template<typename T>
array<T>& array<T>::operator=(const array& source)
{
    /* Check if I am assigning myself */
    if(&source == this)
        return *this;

    delete[] m_arr;
    m_size = source.m_size;
    m_arr = new T[source.m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_arr[i] = source.m_arr[i];
    }

    return *this;
}

template<typename T>
T &array<T>::operator[](int index)
{
    // Bound check
    if(index < 0 || index >= m_size)
    {
        std::cout << "Error: Out of bounds access" << std::endl;
        exit(1);
    }
    
    // Return the value arrayby reference
    return m_arr[index];
}

template<typename T>
int array<T>::GetSize()
{
    return m_size;
}