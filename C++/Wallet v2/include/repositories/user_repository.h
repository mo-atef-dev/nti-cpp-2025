#pragma once

#include <user_entity.h>

class UserRepository
{
    public:
    virtual User GetById(int id) = 0;
    virtual User GetByName(std::string name) = 0;

    virtual void DeleteById(int id) = 0;
};