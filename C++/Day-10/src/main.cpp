#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <chrono>
#include <atomic>
#include <semaphore>
#include <mutex>

const size_t SIZE = 1000000;

std::array<int, SIZE> globalArray;

void InitArray()
{
    for(int& i : globalArray)
    {
        i = 1;
    }
}

int SumArraySequential()
{
    int sum = 0;
    for(int i : globalArray)
    {
        sum += i;
    }
    return sum;
}

void PartialSum(int start, int end, int& result, std::exception_ptr& err)
{
    try
    {
        int localSum = 0;
        for(int i = start; i < end; i++)
        {
            localSum += globalArray[i];
        }
        result = localSum;
    }
    catch(...)
    {
        err = std::current_exception();
    }
}

const size_t numThreads = 2;

int SumArrayParallel()
{
    std::array<std::thread, numThreads> threads;
    std::array<int, numThreads> results;
    std::array<std::exception_ptr, numThreads> errors;
    int sum = 0;

    size_t slice = SIZE/numThreads;
    size_t offset = 0;
    size_t end = slice;

    for(size_t i = 0; i < numThreads; i++)
    {
        threads[i] = std::thread{PartialSum, offset, end, std::ref(results[i]), std::ref(errors[i])};
        offset += slice;
        end += slice;
    }

    for(size_t i = 0; i < numThreads; i++)
    {
        if(threads[i].joinable())
        {
            threads[i].join();
            sum += results[i];
            if(errors[i])
                std::rethrow_exception(errors[i]);
        }
    }

    return sum;
}

int main()
{
    InitArray();

    auto start = std::chrono::high_resolution_clock::now();
    //int sum = SumArraySequential();
    int sum = SumArrayParallel();
    auto end = std::chrono::high_resolution_clock::now();

    auto time = end - start;

    int milliseconds = time.count() / 1E6;
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Time = " << milliseconds << "ms\n";
}
