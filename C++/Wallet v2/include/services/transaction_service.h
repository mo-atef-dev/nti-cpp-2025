#pragma once

#include "user_repository.h"
#include "transaction_repository.h"

class Application;

struct TransactionResult
{
    /**
     * Success: The transaction is performed successfully
     * Fail: The transaction failed due to wrong data
     * Error: The transaction failed due to an error in the system
     */
    enum class Status {Success, Fail, Error};

    Status status = Status::Error;
    const char* message = nullptr;
};

class TransactionService
{
    public:
    TransactionService(Application& application);
    TransactionResult TransferMoney(int sourceUserId, int destUserId, double amount);
    TransactionResult TransferMoney(const std::string& sourceUserName, const std::string& destUserName, double amount);

    private:
    TransactionRepository* m_transactionRepository;
    UserRepository* m_userRepository;
    User* m_currentUser;
};