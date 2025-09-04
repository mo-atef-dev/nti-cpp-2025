#include "demos.h"
#include "application.h"

int main()
{
    Application app{"user_sample.csv", "transaction_sample.csv"};

    app.Run();
}