#pragma once

#include <string>

/**
 * This class represents a User in our application
 * during runtime
 */
class User
{
    public:
    User(int id, std::string name, double balance = 0, std::string password = std::string{});

    int GetId();
    const std::string GetName();
    double GetBalance();
    const std::string GetPassword();

    private:
    int m_id;
    std::string m_name;
    double m_balance;
    std::string m_password;
};