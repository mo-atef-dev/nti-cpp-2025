#include "application.h"

/**
 * Sending (*this) as an argument in the initialization is dangerous
 * but I am doing it here anyway because I know I will not use the
 * application object inside the constructor of menu manager
 */
Application::Application(std::string usersFileName,
    std::string transactionsFileName) : m_menuManager{*this} 
{
    
}

void Application::Run()
{
    m_menuManager.Run();
}

MenuManager& Application::GetMenuManager()
{
    return m_menuManager;
}