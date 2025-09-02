#include "CSVFiles.h"
#include <fstream>
#include <exception>
#include <string>
#include <sstream>

// For debugging
#include <iostream>
#include <iomanip>

CSVFile CSVReader::ReadFile(const std::string &path)
{
    std::ifstream fileStream{path};

    /**
     * Detect errors on the stream and throw exceptions
     */
    if(fileStream.fail())
        throw std::ios_base::failure{"Failed to open the file"};
    if(fileStream.bad())
        throw std::bad_exception{};

    if(fileStream.eof())
        throw bad_file_format{"File is empty"};

    // Read the line in a string using getline
    std::string lineString;
    std::getline(fileStream, lineString);

    // Use an input string stream on the line
    std::istringstream lineStream;
    lineStream.str(lineString);

    // Read the headers and place them in a vector
    std::vector<std::string> headers;
    while(!lineStream.eof())
    {
        std::string header;
        std::getline(lineStream, header, ',');

        headers.push_back(header);
    }

    // Now until we reach the end of the file keep reading rows
    CSVFile out{headers};
    while(!fileStream.eof())
    {
        CSVRow row;

        std::getline(fileStream, lineString);
        lineStream.clear();
        lineStream.str(lineString);

        // For each header add a value in the CSV row
        for(int i = 0; i < headers.size(); i++)
        {
            if(!lineStream.good())
                throw bad_file_format{"Row doesn't contain all columns"};

            std::string value;
            std::getline(lineStream, value, ',');

            row.InsertValue(headers[i], value);
        }

        out.AppendRow(row);
    }

    return out;
}

void CSVWriter::WriteFile(const std::string &path, const CSVFile &file)
{
}

std::string &CSVRow::operator[](const std::string &column)
{
    return m_rowData.at(column);
}

void CSVRow::InsertValue(const std::string &column, const std::string &value)
{
    m_rowData.insert({column, value});
}

CSVFile::CSVFile(std::vector<std::string> headers) : m_headers{headers}
{
}

CSVRow &CSVFile::operator[](int index)
{
    return m_data[index];
}

void CSVFile::DeleteRow(int index)
{
    m_data.erase(m_data.begin() + index);
}

void CSVFile::AppendRow(CSVRow row)
{
    m_data.push_back(row);
}

void CSVFile::InsertRow(CSVRow row, int index)
{
    m_data.insert(m_data.begin() + index, row);
}

void CSVFile::Print()
{
    for(auto header: m_headers)
    {
        std::cout << std::setw(10) << header;
    }

    std::cout << std::endl;

    for(auto row: m_data)
    {
        for(auto header: m_headers)
        {
            std::cout << std::setw(10) << row[header];
        }

        std::cout << std::endl;
    }
}
