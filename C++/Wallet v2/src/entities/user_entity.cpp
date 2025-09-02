#include "user_entity.h"

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
