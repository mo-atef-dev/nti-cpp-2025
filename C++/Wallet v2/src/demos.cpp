#include <iostream>
#include "user_csv_repository.h"
#include "transaction_csv_repository.h"
#include "repository_exceptions.h"

void user_repository_demo()
{
    UserRepository* repo = new UserCSVRepository{"./user_sample.csv"};

    std::cout << "File opened successfully!" << "\n\n";
    std::string input;

    while(true)
    {
        std::cout << "Enter the name you would like to query (press Ctrl + D to exit): " << '\n';

        std::cin >> input;

        if(std::cin.eof())
        {
            break;
        }

        try
        {
            User u = repo->GetByName(input);

            std::cout << '\n';

            std::cout << "Id: " << u.GetId() << std::endl;
            std::cout << "Name: " << u.GetName() << std::endl;
            std::cout << "Balance: " << u.GetBalance() << std::endl;
            std::cout << "Password: " << u.GetPassword() << std::endl;

            std::cout << '\n';
        }
        catch(const not_found& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}

void transaction_repository_demo()
{
    TransactionRepository* repo = new TransactionCSVRepository{"./transaction_sample.csv"};

    std::cout << "File opened successfully!" << "\n\n";
    int input;

    while(true)
    {
        std::cout << "Enter the id  of the user you would like to query (press Ctrl + D to exit): " << '\n';

        std::cin >> input;

        if(std::cin.eof())
        {
            break;
        }

        try
        {
            std::vector<Transaction> transactions = repo->GetUserTransactions(input);

            for(auto t : transactions)
            {
                std::cout << std::setw(5) << "Id: " << t.m_id;
                std::cout << std::setw(15) << "Src id: " << t.m_sourceUserId;
                std::cout << std::setw(15) << "Dest id: " << t.m_destUserId;
                std::cout << std::setw(15) << "Amount: " << t.m_amount;
                std::cout << std::setw(20) << "Date: " << t.m_date;
                std::cout << '\n';
            }
            std::cout << '\n';
        }
        catch(const not_found& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}