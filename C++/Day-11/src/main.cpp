#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <semaphore>
#include <atomic>
#include <functional>
#include <queue>
#include <future>
#include <condition_variable>

class AccountMonitor
{

    public:
    void Deposit(double amount)
    {
        std::unique_lock l{m_mutex};
        balance += amount;
        m_deposit.notify_all();
    }

    void Withdraw(double amount)
    {
        std::unique_lock l{m_mutex};
        while(balance < amount)
            m_deposit.wait(l);
        balance -= amount;
    }  

    private:
    double balance = 0;
    std::mutex m_mutex;
    std::condition_variable m_deposit;
};

std::counting_semaphore sem{2};

void ThreadFunction(AccountMonitor& monitor)
{
    std::cout << "Trying to withdraw 5000\n";
    monitor.Withdraw(5000);
    std::cout << "5000 taken successfully\n";

    sem.acquire();
}

int main()
{
    AccountMonitor monitor;
    std::thread t1{ThreadFunction, std::ref(monitor)};
    std::thread t2{ThreadFunction, std::ref(monitor)};

    while(true)
    {
        if(sem.try_acquire())
            sem.release();
        else
            break;

        double amount = 0;
        std::cout << "Enter the amount you want to deposit\n";
        std::cin >> amount;
        monitor.Deposit(amount);
    }

    t1.join();
    t2.join();
}
