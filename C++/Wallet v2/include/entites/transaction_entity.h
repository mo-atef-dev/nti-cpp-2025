#pragma once

#include <string>
#include <chrono>
/**
 * I decided to do something different in this class
 * 
 * I am going to make all members public instead of
 * making getter and setter functions
 * 
 * This is generally bad practice as this doesn't provide
 * encapsulation or abstraction, making changed to code
 * harder
 * 
 * In this case the transaction object is a simple one
 * so it may not make a big difference, but as we change
 * the application some problems might occur
 */
class Transaction
{
    using date_type = std::chrono::time_point<std::chrono::system_clock>;

    public:
    int m_id;
    int m_sourceUserId;
    int m_destUserId;
    double m_amount;
    date_type m_date;

    Transaction(int id, int sourceUserId = -1, int destUserId = -1,
        double amount = 0, date_type date = std::chrono::system_clock::now())
        : m_id{id}, m_sourceUserId{sourceUserId}, m_destUserId{destUserId},
        m_amount{amount}, m_date{date}
    {
        
    }
};