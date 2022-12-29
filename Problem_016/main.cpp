#include <iostream>

#include "OrderLog.cpp"

int main()
{
    std::cout<<"Daily Coding Problem 16"<<std::endl;

    OrderLog myOrderLog;
    
    int size = 11;
    for(int i = 0 ; i < size ; i ++)
        myOrderLog.record(i);

    std::cout<<myOrderLog.getLast(10)<<std::endl;

    myOrderLog.printRecord();

    return 0;
}