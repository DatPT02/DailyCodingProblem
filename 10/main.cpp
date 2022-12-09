#include <iostream>
#include <functional>
#include <thread>
#include <chrono>

void job()
{
    std::cout<<"Job started"<<std::endl;
}

void scheduler(std::function<void()>func, unsigned int time)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    func();
}

int main()
{
    std::cout<<"Daily Coding Problem 10"<<std::endl;

    scheduler(job, 3000);

    return 0;
}