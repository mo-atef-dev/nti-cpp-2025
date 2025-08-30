#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

class Record
{
    public:
    void FromString(std::istream& inputStream)
    {
        std::string s;

        inputStream >> std::ws;

        std::getline(inputStream, s, ',');
        id = std::stoi(s);
        std::getline(inputStream, s, ',');
        name = s;
        std::getline(inputStream, s, ',');
        balance = std::stod(s);
        std::getline(inputStream, s, ',');
        yearOfBirth = std::stoi(s);
    }

    void Print()
    {
        std::cout << "Id: " << id << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "Year of birth: " << yearOfBirth << std::endl;
    }
    private:
    int id;
    double balance;
    std::string name;
    int yearOfBirth;
};

int main()
{
    Record r;
    std::ifstream inputFile{"./myFile.txt"};
    std::istringstream ss;

    std::filesystem::path p{"./myFile.txt"};
    std::filesystem::exists(p);

    p.string();

    while(inputFile)
    {
        Record r;
        r.FromString(inputFile);
        r.Print();
    }
}