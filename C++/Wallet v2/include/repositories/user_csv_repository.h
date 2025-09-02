#pragma once

#include "user_repository.h"
#include "csv_files.h"

class UserCSVRepository : public UserRepository
{
    public:
    UserCSVRepository(const std::string filePath);

    User GetById(int id) override;
    User GetByName(std::string name) override;

    void DeleteById(int id) override;

    private:
    CSVFile m_file;

    /**
     * Here I am using constant strings for the names
     * of the columns in the file
     * This is just for making things clear and avoid
     * writing the same string each time
     */
    const std::string COLUMN_ID = "id";
    const std::string COLUMN_NAME = "name";
    const std::string COLUMN_PASSWORD = "password";
    const std::string COLUMN_BALANCE = "balance";
};