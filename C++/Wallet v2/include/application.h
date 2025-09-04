#pragma once

#include <string>
#include <memory>

#include "menu_manager.h"
#include "user_csv_repository.h"
#include "transaction_csv_repository.h"

class LoginService;
class TransactionService;

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

    /**
     * These are function to get references to the different
     * application resources and services
     */
    UserRepository* GetUserRepository();
    TransactionRepository* GetTransactionRepository();

    std::unique_ptr<LoginService> GetLoginService();
    std::unique_ptr<TransactionService> GetTransactionService();

    User* GetCurrentUser();
    void SetCurrentUser(User* user);

    MenuManager& GetMenuManager();
    private:
    MenuManager m_menuManager;

    std::unique_ptr<User> m_currentUser;

    std::unique_ptr<UserRepository> m_userRepository;
    std::unique_ptr<TransactionRepository> m_transactionRepository;
};