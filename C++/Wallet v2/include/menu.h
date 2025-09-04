#pragma once
#include <iostream>
#include "menu_manager.h"
#include <memory>

class LoginService;
class MenuManager; // Forward declare the class MenuManager

enum class MenuResult {Continue, ClearAndContinue, Exit};

class Menu
{
    public:
    Menu(MenuManager& menuManager);

    /**
     * Since we have a virtual function we should make
     * the destructor virtual.
     */
    virtual ~Menu();

    /**
     * We want display function to be virtual because
     * each derived class from Menu will implement it
     * according to its own logic.
     */
    virtual MenuResult Display() const = 0;

    protected:
    MenuManager& m_menuManager;
};

class WelcomeMenu : public Menu
{
    public:
    WelcomeMenu(MenuManager& menuManager);

    MenuResult Display() const override;
    
};

class LoginMenu : public Menu
{
    public:
    LoginMenu(MenuManager& menuManager);

    MenuResult Display() const override;

    private:
    std::unique_ptr<LoginService> m_loginService;
};

class OptionsMenu : public Menu
{
    public:
    OptionsMenu(MenuManager& menuManager);

    MenuResult Display() const override;
};