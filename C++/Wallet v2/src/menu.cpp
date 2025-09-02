#include "menu.h"

Menu::Menu(MenuManager& menuManager) : m_menuManager(menuManager)
{

}

Menu::~Menu()
{
}

WelcomeMenu::WelcomeMenu(MenuManager& menuManager) : Menu(menuManager) 
{

}

MenuResult WelcomeMenu::Display() const
{
    std::cout << "#### Welcome to smart wallet ####" << std::endl;
    std::cout << std::endl;
    std::cout << "(L) Login" << std::endl;
    std::cout << "(Q) Quit" << std::endl;

    char choice;
    std::cin >> choice;

    switch(choice)
    {
        case 'l':
        m_menuManager.ChangeMenu(new LoginMenu(m_menuManager));
        break;
        case 'q':
        return MenuResult::Exit;
        break;
    }

    return MenuResult::ClearAndContinue;
}

LoginMenu::LoginMenu(MenuManager &menuManager) : Menu(menuManager) 
{

}

MenuResult LoginMenu::Display() const
{
    std::string userName;
    std::string password;

    std::cout << "#### Please enter your credentials ####" << std::endl;
    std::cout << std::endl;
    std::cout << "Username: ";
    std::cin >> userName;
    std::cout << "Password: ";
    std::cin >> password;

    if(userName == "admin" && password == "admin")
    {
        m_menuManager.ChangeMenu(new OptionsMenu(m_menuManager));    
        return MenuResult::ClearAndContinue;
    }
    
    std::cout << "Wrong username or password" << std::endl;
    std::cout << std::endl;
    std::cout << "(L) Try logging in again" << std::endl;
    std::cout << "(Q) Quit" << std::endl;

    char choice;
    std::cin >> choice;

    switch(choice)
    {
        case 'l':
        m_menuManager.ChangeMenu(new LoginMenu(m_menuManager));
        break;
        case 'q':
        return MenuResult::Exit;
        break;
    }

    m_menuManager.ChangeMenu(new WelcomeMenu(m_menuManager));

    return MenuResult::ClearAndContinue;
}

OptionsMenu::OptionsMenu(MenuManager &menuManager) : Menu(menuManager)
{
}

MenuResult OptionsMenu::Display() const
{
    char choice;

    std::cout << "What do you want to do?" << std::endl << std::endl;

    std::cout << "(S) Account statement" << std::endl;
    std::cout << "(B) Show balance" << std::endl;
    std::cout << "(T) Perform transaction" << std::endl;
    std::cout << "(W) Withdraw money" << std::endl;
    std::cout << "(D) Deposit money" << std::endl;
    std::cout << "(L) Logout" << std::endl;
    std::cout << "(Q) Quit" << std::endl;

    std::cin >> choice;

    switch(choice)
    {
        case 's':
        // Should go to statement menu here
        break;
        case 'b':
        // Should go to balance menu here
        break;
        case 't':
        // Should go to transaction menu here
        break;
        case 'w':
        // Should go to withdraw menu here
        break;
        case 'd':
        // Should go to deposit menu here
        break;
        case 'l':
        m_menuManager.ChangeMenu(new WelcomeMenu(m_menuManager));
        break;
        case 'q':
        return MenuResult::Exit;
        break;
    }

    return MenuResult::Continue;
}
