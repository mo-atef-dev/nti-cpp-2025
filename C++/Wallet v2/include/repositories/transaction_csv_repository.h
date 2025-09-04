#pragma once

#include "csv_files.h"
#include "transaction_repository.h"
#include <vector>

class TransactionCSVRepository : public TransactionRepository
{
    public:
    TransactionCSVRepository(const std::string filePath);

    Transaction GetById(int id) override;
    std::vector<Transaction> GetUserTransactions(int userId, int number = 10) override;

    void Insert(const Transaction& transaction) override;
    void Update(int id, const Transaction& transaction) override;

    void DeleteById(int id) override;

    void Sync() override;

    private:
    CSVFile m_file;
    const std::string m_filePath;

    /**
     * Here I am using constant strings for the names
     * of the columns in the file
     * This is just for making things clear and avoid
     * writing the same string each time
     */
    const std::string COLUMN_ID = "id";
    const std::string COLUMN_SRC_USER_ID = "src_user_id";
    const std::string COLUMN_DEST_USER_ID = "dest_user_id";
    const std::string COLUMN_AMOUNT = "amount";
    const std::string COLUMN_DATE = "date";
};