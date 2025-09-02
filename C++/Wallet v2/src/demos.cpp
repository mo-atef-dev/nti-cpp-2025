#include <iostream>
#include "user_csv_repository.h"
#include "repository_exceptions.h"

void user_repository_demo()
{
    UserRepository* repo = new UserCSVRepository{"./sample.csv"};

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