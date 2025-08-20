#pragma once

#include "menu.h"

class Menu;

class MenuManager
{
    public:
    MenuManager();
    MenuManager(const Menu* firstMenu);
    
    void ChangeMenu(const Menu* newMenu);
    void Run();

    private:
    const Menu* m_currentMenu;
};