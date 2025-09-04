#include "transaction_service.h"
#include "repository_exceptions.h"
#include "application.h"

TransactionService::TransactionService(Application &application)
{
    m_userRepository = application.GetUserRepository();
    m_transactionRepository = application.GetTransactionRepository();
    m_currentUser = application.GetCurrentUser();
}

TransactionResult TransactionService::TransferMoney(int sourceUserId, int destUserId, double amount)
{
    using enum TransactionResult::Status;

    if(m_currentUser->GetId() != sourceUserId)
        return {Fail, "Can only transfer from the logged in user"};

    if(amount <= 5)
        return {Fail, "Minimum amount of transfer is 5 pounds"};

    User sourceUser = m_userRepository->GetById(sourceUserId);
    User destUser = m_userRepository->GetById(destUserId);

    double sourceBalance = sourceUser.GetBalance();
    double destBalance = destUser.GetBalance();

    // The transaction object to store in the transaction repository
    Transaction transaction = {0,
        sourceUserId,
        destUserId,
        amount,
        std::chrono::system_clock::now()
        };

    if(sourceUser.GetBalance() < amount)
        return {Fail, "Not enough funds"};

    try
    {
        sourceUser.SetBalance(sourceBalance - amount);
        destUser.SetBalance(destBalance + amount);

        m_userRepository->Update(sourceUserId, sourceUser);
        m_userRepository->Update(destUserId, destUser);

        m_transactionRepository->Insert(transaction);
    }
    catch(const std::logic_error& e)
    {
        std::cerr << e.what() << '\n';
        return {Error, "Transaction failed due to system error"};
    }
    catch(...)
    {
        return {Error, "Transaction failed due to system error"};
    }
    
    m_userRepository->Sync();
    m_transactionRepository->Sync();

    return {Success, "Transaction completed successfully"};
}

TransactionResult TransactionService::TransferMoney(const std::string &sourceUserName, const std::string &destUserName, double amount)
{
    using enum TransactionResult::Status;

    // Get the user ids
    int srcId;
    int destId;

    try
    {
        srcId = m_userRepository->GetByName(sourceUserName).GetId();
        destId = m_userRepository->GetByName(destUserName).GetId();
    }
    catch(const not_found& e)
    {
        return {Fail, "Couldn't find one or both users of the transaction, make sure they are spelled correctly"};
    }
    

    return TransferMoney(srcId, destId, amount);
}
