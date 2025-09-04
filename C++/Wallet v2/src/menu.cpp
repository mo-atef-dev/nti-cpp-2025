#include "menu.h"
#include "application.h"
#include "login_service.h"
#include "transaction_service.h"
#include <iomanip>

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
    m_loginService = m_menuManager.GetApplication()->GetLoginService();
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

    if(m_loginService->Login(userName, password))
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
        // Do nothing
        break;
        case 'q':
        return MenuResult::Exit;
        break;
    }

    return MenuResult::ClearAndContinue;
}

OptionsMenu::OptionsMenu(MenuManager &menuManager) : Menu(menuManager)
{
}

MenuResult OptionsMenu::Display() const
{
    char choice;

    const std::string_view userName = m_menuManager.GetApplication()->GetCurrentUser()->GetName();

    std::cout << "Hello " << userName << std::endl;
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
        m_menuManager.ChangeMenu(new TransactionMenu(m_menuManager));
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

    return MenuResult::ClearAndContinue;
}

TransactionMenu::TransactionMenu(MenuManager &menuManager) : Menu(menuManager)
{
    m_transactionService = m_menuManager.GetApplication()->GetTransactionService();
}

MenuResult TransactionMenu::Display() const
{
    std::string currentUserName = m_menuManager.GetApplication()->GetCurrentUser()->GetName();
    std::string destUserName;
    double amount;

    std::cout << "Enter the user you would like to transfer money to: ";
    std::cin >> destUserName;

    std::cout << "Enter the amount you want to transfer: ";
    std::cin >> amount;

    std::cout << "You are requestion the following transaction\n";
    std::cout << std::setw(10) << "## To user: " << destUserName << '\n';
    std::cout << std::setw(10) << "## Amount: " << amount << "\n\n";

    char c;
    std::cout << "(C) Confirm\n";
    std::cout << "(Any other key) Go back and cancel\n";
    std::cin >> c;

    TransactionResult result;

    switch(c)
    {
        case 'c':
        result = m_transactionService->TransferMoney(currentUserName, destUserName, amount);
        break;
        default:
        m_menuManager.ChangeMenu(new OptionsMenu{m_menuManager});
        return MenuResult::ClearAndContinue;
        break;
    }

    std::cout << result.message << '\n';

    std::cout << "Would you like to perform another transaction?\n";
    std::cout << "(Y) Yes\n";
    std::cout << "(Any other key) Go back and cancel\n";
    std::cin >> c;

    switch(c)
    {
        case 'c' || 'C':
        break;
        default:
        m_menuManager.ChangeMenu(new OptionsMenu{m_menuManager});
        break;
    }

    return MenuResult::ClearAndContinue;
}
