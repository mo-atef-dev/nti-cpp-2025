#pragma once

#include "transaction_entity.h"

class TransactionRepository
{
    public:
    virtual Transaction GetById(int id) = 0;
    virtual std::vector<Transaction> GetUserTransactions(int userId, int number = 10) = 0;

    virtual void Insert(const Transaction& transaction) = 0;
    virtual void Update(int id, const Transaction& transaction) = 0;

    virtual void DeleteById(int id) = 0;
};