#pragma once

#include <iostream>

template<typename T>
class owner_pointer
{
    public:
    owner_pointer(int n)
    {
        std::cout << "Owner pointer created" << std::endl;
        m_arr = new T[n];
    }

    owner_pointer(const owner_pointer&) = delete;
    owner_pointer& operator=(const owner_pointer&) = delete;

    ~owner_pointer()
    {
        std::cout << "Owner pointer deleted" << std::endl;
        delete[] m_arr;
    }

    T& operator*()
    {
        return *m_arr;
    }

    T& operator[](int i)
    {
        return m_arr[i];
    }
    private:
    T* m_arr;
};

class array
{
    public:
    array() = delete;
    array(int size);
    array(const array& source);

    array& operator=(const array&) = delete;

    int Read(int index);
    void Write(int index, int value);
    int GetSize();

    private:
    owner_pointer<int> m_arr;
    int m_size;
};
