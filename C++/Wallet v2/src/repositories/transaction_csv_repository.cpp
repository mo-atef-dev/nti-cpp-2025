#include "transaction_csv_repository.h"
#include "time_strings.h"
#include "repository_exceptions.h"

TransactionCSVRepository::TransactionCSVRepository(const std::string filePath) : m_filePath{filePath}
{
    m_file = CSVReader::ReadFile(filePath);
}

Transaction TransactionCSVRepository::GetById(int id)
{
    for(size_t i = 0; i < m_file.GetNumberOfRows(); i++)
    {
        auto currentId = std::stoi(m_file[i][COLUMN_ID]);
        auto currentSrcUserId = std::stoi(m_file[i][COLUMN_SRC_USER_ID]);
        auto currentDestUserId = std::stoi(m_file[i][COLUMN_DEST_USER_ID]);
        auto currentAmount = std::stod(m_file[i][COLUMN_AMOUNT]);
        auto currentDate = TimeParser::FromString(m_file[i][COLUMN_DATE]);

        if(currentId == id)
        {
            return Transaction{currentId, currentSrcUserId, currentDestUserId, currentAmount, currentDate};
        }
    }

    throw not_found{"Requested transaction not found in file"};
}

std::vector<Transaction> TransactionCSVRepository::GetUserTransactions(int userId, int number)
{
    std::vector<Transaction> result;

    for(size_t i = 0; i < m_file.GetNumberOfRows(); i++)
    {
        auto currentId = std::stoi(m_file[i][COLUMN_ID]);
        auto currentSrcUserId = std::stoi(m_file[i][COLUMN_SRC_USER_ID]);
        auto currentDestUserId = std::stoi(m_file[i][COLUMN_DEST_USER_ID]);
        auto currentAmount = std::stod(m_file[i][COLUMN_AMOUNT]);
        auto currentDate = TimeParser::FromString(m_file[i][COLUMN_DATE]);

        if(currentSrcUserId == userId || currentDestUserId == userId)
        {
            result.push_back(Transaction{currentId, currentSrcUserId, currentDestUserId, currentAmount, currentDate});
        }

        if(result.size() > number)
        {
            break;
        }
    }

    return result;
}

void TransactionCSVRepository::Insert(const Transaction& transaction)
{
    CSVRow row{};

    int id = 0;
    if(m_file.GetNumberOfRows() == 0)
        id = 0; // Set the id to 0 if there are no rows
    else
    {
        // Get the last id and increment by 1
        id = std::stoi(m_file[m_file.GetNumberOfRows() - 1][COLUMN_ID]) + 1;
    }

    row.InsertValue(COLUMN_ID, std::to_string(id));
    row.InsertValue(COLUMN_SRC_USER_ID, std::to_string(transaction.m_sourceUserId));
    row.InsertValue(COLUMN_DEST_USER_ID, std::to_string(transaction.m_destUserId));
    row.InsertValue(COLUMN_AMOUNT, std::to_string(transaction.m_amount));
    row.InsertValue(COLUMN_DATE, TimeParser::ToString(transaction.m_date));

    m_file.AppendRow(row);
}

void TransactionCSVRepository::Update(int id, const Transaction& transaction)
{
    for(size_t i = 0; i < m_file.GetNumberOfRows(); i++)
    {
        auto currentId = std::stoi(m_file[i][COLUMN_ID]);

        if(currentId == id)
        {
            // Update all fields except id

            m_file[i][COLUMN_SRC_USER_ID] = std::to_string(transaction.m_sourceUserId);
            m_file[i][COLUMN_DEST_USER_ID] = std::to_string(transaction.m_destUserId);
            m_file[i][COLUMN_AMOUNT] = std::to_string(transaction.m_amount);
            m_file[i][COLUMN_DATE] = TimeParser::ToString(transaction.m_date);
            return;
        }
    }
}

void TransactionCSVRepository::DeleteById(int id)
{
    for(size_t i = 0; i < m_file.GetNumberOfRows(); i++)
    {
        auto currentId = std::stoi(m_file[i][COLUMN_ID]);

        if(currentId == id)
        {
            m_file.DeleteRow(i);
            return;
        }
    }
}

void TransactionCSVRepository::Sync()
{
    CSVWriter::WriteFile(m_filePath, m_file);
}
