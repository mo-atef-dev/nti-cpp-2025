#pragma once

#include "menu.h"
#include <memory>

class Menu;
class Application;

class MenuManager
{
    public:
    MenuManager(Application& application);
    MenuManager(const Menu* firstMenu, Application& application);
    
    Application* GetApplication();

    void ChangeMenu(const Menu* newMenu);
    void Run();

    private:
    /**
     * I have changed the currentMenu member to
     * be a unique pointer instead of a raw pointer
     * to follow RAII principle
     */
    std::unique_ptr<const Menu> m_currentMenu;

    /**
     * This is a reference to the application object
     */
    Application& m_application;
};