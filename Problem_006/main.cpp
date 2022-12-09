#include <iostream>

#include "XOR.cpp"

int main ()
{
    std::cout<<"Daily Coding Problem 6"<<std::endl;

    XORList* myXorList = new XORList();

    myXorList->add(0);
    myXorList->add(5);
    myXorList->add(10);
    myXorList->add(20);
    myXorList->add(100);

    myXorList->traverse();

    std::cout<<std::endl;
    std::cout<<myXorList->get(2)->data<<std::endl;

    return 0;
}