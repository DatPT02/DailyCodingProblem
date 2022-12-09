#include <iostream>


void swap_array_value_at_index(int arr[], int firstIndex, int secondIndex)
{
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

int first_missing_int(int arr[], int arr_length)
{
    int missingNumber = arr_length;
    for(int i = 0; i < arr_length; i ++)
    {
        while(0 < arr[i] <= arr_length && arr[i] != arr[arr[i]-1]){
            swap_array_value_at_index(arr, i, arr[i]-1);
        }
    }

    for(int i = 0; i < arr_length; i ++)
    {
        if(arr[i] != i + 1){
            missingNumber = i + 1;
            break;
        }
    }
    return missingNumber;
}

int main()
{
    std::cout<<"Daily Coding Problem 4"<< std::endl;

    const int arr_length = 10;
    int arr[arr_length] = {1, 2, 0};
    
    std::cout<<"First missing positive interger: "<< first_missing_int(arr, arr_length);
    return 0;
}