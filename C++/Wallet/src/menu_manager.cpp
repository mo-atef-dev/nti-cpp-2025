#include "menu_manager.h"

MenuManager::MenuManager()
{
    m_currentMenu = new WelcomeMenu(*this);
}

MenuManager::MenuManager(const Menu *firstMenu) : m_currentMenu(firstMenu)
{

}

void MenuManager::ChangeMenu(const Menu *newMenu)
{
    delete m_currentMenu; // Delete the old Menu pointed at by m_currentMenu
    m_currentMenu = newMenu; // Set the new Menu
}

void MenuManager::Run()
{
    MenuResult result = MenuResult::Continue;

    /**
     * This is the main loop of the application.
     * It wil keep running until Display returns
     * MenuResult::Exit.
     */
    while (result != MenuResult::Exit)
    {
        result = m_currentMenu->Display();

        if(result == MenuResult::ClearAndContinue)
            std::cout << "\033[2J\033[1;1H"; // This is to clear the screen
    }
}
