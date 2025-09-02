#include "user_csv_repository.h"
#include "repository_exceptions.h"

UserCSVRepository::UserCSVRepository(const std::string filePath)
{
    m_file = CSVReader::ReadFile(filePath);
}

User UserCSVRepository::GetById(int id)
{
    for(size_t i = 0; i < m_file.GetNumberOfRows(); i++)
    {
        auto currentId = std::stoi(m_file[i][COLUMN_ID]);
        auto currentName = m_file[i][COLUMN_NAME];
        auto currentBalance = std::stod(m_file[i][COLUMN_BALANCE]);
        auto currentPassword = m_file[i][COLUMN_PASSWORD];

        if(currentId == id)
        {
            return User{currentId, currentName, currentBalance, currentPassword};
        }
    }

    throw not_found{"Requested User not found in file"};
}

User UserCSVRepository::GetByName(std::string name)
{
    for(size_t i = 0; i < m_file.GetNumberOfRows(); i++)
    {
        auto currentId = std::stoi(m_file[i][COLUMN_ID]);
        auto currentName = m_file[i][COLUMN_NAME];
        auto currentBalance = std::stod(m_file[i][COLUMN_BALANCE]);
        auto currentPassword = m_file[i][COLUMN_PASSWORD];

        if(currentName == name)
        {
            return User{currentId, currentName, currentBalance, currentPassword};
        }
    }

    throw not_found{"Requested User not found in file"};
}

void UserCSVRepository::DeleteById(int id)
{
    for(size_t i = 0; i < m_file.GetNumberOfRows(); i++)
    {
        int currentId = std::stoi(m_file[i][COLUMN_ID]);

        if(currentId == id)
        {
            m_file.DeleteRow(i);
            return;
        }
    }
}
