#include <iostream>

using namespace std;

//With division
void solveWithDivision(int array[], int totalElement)
{
    int totalArrayValue = 1;

    for(int i = 0; i < totalElement; i++)
    {
        totalArrayValue *= array[i];
    }

    for(int i = 0; i < totalElement; i++)
    {
        cout<< totalArrayValue / array[i]<< " ";
    }

    cout<<endl;
}

int main()
{
    std::cout<<"Daily Coding Problem 2"<<std::endl;

    int totalElement;
    int array[100];

    cout<<"Enter total element: ";
    cin>>totalElement;

    cout<<"Enter array: ";
    for(int i = 0; i < totalElement; i++)
    {
        cin>>array[i];
    }

    solveWithDivision(array, totalElement);

    return 0;
}