#pragma once

#include <map>
#include <vector>
#include <string>
#include <stdexcept>

class bad_file_format : public std::logic_error
{
    public:
    bad_file_format(const char* err) : std::logic_error{err}
    {
        
    }
};

class CSVRow
{
    public:
    std::string& operator[](const std::string& column);
    const std::string& operator[](const std::string& column) const;

    void InsertValue(const std::string& column, const std::string& value);

    private:
    std::map<std::string, std::string> m_rowData;
};

class CSVFile
{
    public:
    CSVFile();
    CSVFile(std::vector<std::string> headers);

    CSVRow& operator[](int index);
    const CSVRow& operator[](int index) const;

    std::vector<std::string> GetHeaders() const;
    size_t GetNumberOfRows() const;

    void DeleteRow(int index);
    void AppendRow(CSVRow row);
    void InsertRow(CSVRow row, int index);

    void Print();

    private:
    std::vector<CSVRow> m_data;
    std::vector<std::string> m_headers;
};

class CSVReader
{
    public:
    static CSVFile ReadFile(const std::string& path);
};

class CSVWriter
{
    public:
    static void WriteFile(const std::string& path, const CSVFile& file);
};