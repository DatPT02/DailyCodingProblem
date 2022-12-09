#include <iostream>

struct pair
{
    int first;
    int last;
    pair() {};
    pair(int a, int b) : first(a), last(b) {};
};

pair cons(int a, int b)
{
    return pair(a,b);
}

int car(pair* pair)
{
    return pair->first;
}

int cdr(pair* pair)
{
    return pair->last;
}

int main ()
{
    std::cout<<"Daily Coding Problem 5"<<std::endl;

    int a = 3;
    int b = 4;

    pair myPair = cons(a,b);

    std::cout<<"car: "<<car(&myPair)<<std::endl;
    std::cout<<"cdr: "<<cdr(&myPair)<<std::endl;

    return 0;
}