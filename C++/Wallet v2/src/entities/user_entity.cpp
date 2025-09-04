#include "user_entity.h"
#include "stdexcept"

User::User(int id, std::string name, double balance, std::string password)
: m_id{id}, m_name{name}, m_balance{balance}, m_password{password}
{
}

int User::GetId()
{
    return m_id;
}

const std::string User::GetName()
{
    return m_name;
}

double User::GetBalance()
{
    return m_balance;
}

const std::string User::GetPassword()
{
    return m_password;
}

void User::SetBalance(double amount)
{
    if(amount < 0)
        throw std::logic_error{"Can't set balance to negative"};

    m_balance = amount;
}
