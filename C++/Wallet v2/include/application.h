#pragma once

#include <string>
#include <memory>

#include "menu_manager.h"

class Application
{
    public:
    Application(std::string usersFileName = "./users_db.csv",
        std::string transactionsFileName = "./transactions_db.csv");

    // Delete the copy and assignment operators
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    /**
     * This function runs the application loop
     */
    void Run();

    MenuManager& GetMenuManager();
    private:
    MenuManager m_menuManager;
};