#pragma once

#include <stdexcept>

/**
 * This is a custom exception for our repositories to
 * throw whenever we don't find an entity
 * 
 * Do you think that this is a good practice? Is
 * there a better way to deal with not found
 * entities or are exceptions good in this case?
 */
class not_found : public std::exception
{
    public:
    not_found(const char* err)
    {
        m_msg = err;
    }

    const char* what() const noexcept override
    {
        return m_msg;
    }

    private:
    const char* m_msg;
};