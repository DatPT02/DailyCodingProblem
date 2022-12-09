#include <iostream>

#define Max_Arr_length 10

int max(int a, int b)
{
    return a > b ? a : b;
}

int largest_nonAdjacent_sum(int arr[])
{
    //max sum with the current element
    int max_include_current = arr[0];

    //max sum without the current element
    int max_exclude_current = 0;

    //new updated exclude value with current element
    int new_max_exclude_current;

    for(int i = 1; i < Max_Arr_length; i ++)
    {
        new_max_exclude_current = max(max_include_current, max_exclude_current);

        max_include_current = max_exclude_current + arr[i];
        max_exclude_current = new_max_exclude_current;
    }

    return max(max_include_current, max_exclude_current);
}

int main()
{
    std::cout<<"Daily Coding Problem 9"<<std::endl;

    int arr[Max_Arr_length] = {5, 1, 1, 5};

    std::cout<<largest_nonAdjacent_sum(arr)<<std::endl;

    return 0;
}