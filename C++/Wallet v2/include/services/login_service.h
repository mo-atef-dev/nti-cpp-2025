#pragma once

#include "application.h"
#include "user_repository.h"
#include <memory>

class LoginService
{
    public:
    LoginService(Application& appliction);

    bool Login(std::string userName, std::string password);

    private:
    Application* m_application;

    UserRepository* m_userRepository;
};