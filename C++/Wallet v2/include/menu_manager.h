#pragma once

#include "menu.h"
#include <memory>

class Menu;

class MenuManager
{
    public:
    MenuManager();
    MenuManager(const Menu* firstMenu);
    
    void ChangeMenu(const Menu* newMenu);
    void Run();

    private:
    /**
     * I have changed the currentMenu member to
     * be a unique pointer instead of a raw pointer
     * to follow RAII principle
     */
    std::unique_ptr<const Menu> m_currentMenu;
};