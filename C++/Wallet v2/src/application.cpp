#include "application.h"

Application::Application(std::string usersFileName,
    std::string transactionsFileName) : m_menuManager{}
{
    
}

void Application::Run()
{

}

MenuManager& Application::GetMenuManager()
{
    return m_menuManager;
}