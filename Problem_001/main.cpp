#include<iostream>
#include<vector>

using namespace std;

bool haveValue(int checkArray[], int arraySize, int checkValue)
{
    for(int i=0; i<arraySize; i++)
    {
        if(checkValue == checkArray[i]) return true;
    }

    return false;
}

int main()
{
    std::cout<<"Daily Coding Problem 1"<<std::endl;

    const int totalElement = 10;
    int elementArray[totalElement] = {10,15,3,7};

    int checkValue = 18;

    for(int i=0; i<totalElement; i++)
    {
        if(haveValue(elementArray, totalElement, checkValue - elementArray[i])){
            cout<<"True: " << elementArray[i] << " + " << (checkValue - elementArray[i])<<endl;
            break;
        }
    }

    return 0;
}