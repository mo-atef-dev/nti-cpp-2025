# Smart Wallet Project File Storage

## File formats

To add storage to our smart wallet application, we need to store the data in files and load the data from files. For this project we will use a file format similar to CSV files.

CSV stands for Comma Separated Values. CSV files are text files where Ecch line the file represents one element or row of data. Each row contains values separated by commas.

Here is a text example for a CSV file

    Name,Age,Job,Experience
    Alice Johnson,29,Software Engineer,5
    Carlos Mendez,35,Data Scientist,8
    Sophie Kim,27,Graphic Designer,4
    David Brown,42,Project Manager,12
    Linda White,31,Marketing Specialist,6

The first line is `Name,Age,Job,Experience` which is the header indicating the fields defined in each position. The header is **optional**, as it doesn't actually contain any data.

Our Smart Wallet program will contain two files called `transaction_db.csv` and `users_db.csv`.

The headers in the `transaction_db.csv` files will be as follows:

    id,src_user_id,dest_user_id,amount,date

The headers in the `users_db.csv` files will be as follows:

    id,username,password,balance

Each file will have the headers in the first line (make sure to ignore them when parsing). An example `users_db.csv` file is shown below:

    id,username,password,balance
    1,moh180,pass1234,40000
    2,john,5543d,2000

## Loading and saving data

Of course CSV files when stored in disk are just text strings. We need to load the data, parse it, and store it an a suitable memory data structure so it can be accessed by our program. This process is known as **deserialization**. The process of converting a runtime data structure in our program to a format suitable for storage or transportation is **serialization**.

When deserializing, make sure to ignore the first line which contains only the headers!

When serializing, make sure to write the header as the first line since it will be expected!

## Hints

Here are some hints and helpful links (you can ignore them, of course) to help you.

### Links for C++ files



[ttps://www.w3schools.com/cpp/cpp_files.asp](https://www.w3schools.com/cpp/cpp_files.asp)

[https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm](https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm)

[https://cplusplus.com/doc/tutorial/files/](https://cplusplus.com/doc/tutorial/files/)

### Tutorial link for parsing CSV

Try parsing CSV yourself. However, if you get stuck, the following is a good helpful link

[https://codesignal.com/learn/courses/parsing-table-data-in-cpp/lessons/parsing-csv-files-and-converting-strings-to-integers-in-cpp](https://codesignal.com/learn/courses/parsing-table-data-in-cpp/lessons/parsing-csv-files-and-converting-strings-to-integers-in-cpp)

### User repository interface

Here is an example user repository abstract class:
```
class UserRepository
{
    public:
    virtual void Load(); // throw exceptions when failed
    virutal void Save();

    virtual User FindUser(int id) = 0; // throw exception if not found
    virtual User FindUser(std::string name) = 0;

    virtual bool UserExists(int id) = 0;
    virtual bool UserExists(std::string name);

    virtual void SaveUser(User user) = 0; // throw exception if failed

    virtual void UpdateUser(int id, User updatedUser) = 0; // throw exception if failed

    virtual void DeleteUser(int id);
};
```