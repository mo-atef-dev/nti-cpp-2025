#include "application.h"
#include "login_service.h"
#include "transaction_service.h"

/**
 * Sending (*this) as an argument in the initialization is dangerous
 * but I am doing it here anyway because I know I will not use the
 * application object inside the constructor of menu manager
 */
Application::Application(std::string usersFileName,
    std::string transactionsFileName) : m_menuManager{*this},
    m_userRepository{new UserCSVRepository{usersFileName}}, m_transactionRepository{new TransactionCSVRepository{transactionsFileName}}
{
    
}

void Application::Run()
{
    m_menuManager.Run();
}

UserRepository *Application::GetUserRepository()
{
    return m_userRepository.get();
}

TransactionRepository* Application::GetTransactionRepository()
{
    return m_transactionRepository.get();
}

std::unique_ptr<LoginService> Application::GetLoginService()
{
    return std::unique_ptr<LoginService>{new LoginService{*this}};
}

std::unique_ptr<TransactionService> Application::GetTransactionService()
{
    return std::unique_ptr<TransactionService>{new TransactionService{*this}};
}

User *Application::GetCurrentUser()
{
    return m_currentUser.get();
}

void Application::SetCurrentUser(User *user)
{
    m_currentUser.reset(user);
}

MenuManager& Application::GetMenuManager()
{
    return m_menuManager;
}