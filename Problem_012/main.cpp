#include <iostream>
#include <vector>

int WaysToClimb(int staircase_steps, std::vector<int> possibleSteps)
{
    if(staircase_steps < 0)
        return 0;
    if(staircase_steps == 0)
        return 1;

    int waysToClimb = 0;

    for(int i : possibleSteps)
    {
        waysToClimb += WaysToClimb(staircase_steps - i, possibleSteps);
    }

    return waysToClimb;
}

int main()
{
    std::cout<<"Daily Coding Problem 12"<<std::endl;

    std::cout<<WaysToClimb(5, {1,3,5})<<std::endl;

    return 0;
}