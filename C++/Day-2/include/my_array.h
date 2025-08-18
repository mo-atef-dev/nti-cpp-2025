#pragma once

class array
{
    public:
    array() = delete;
    array(int size);
    array(const array& source);
    ~array();

    array& operator=(const array&);

    int Read(int index);
    void Write(int index, int value);
    int GetSize();

    private:
    int* m_arr;
    int m_size;
};
