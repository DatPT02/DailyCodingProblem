#include <iostream>

int possible_decode_ways(std::string msg)
{
    if(msg.find("0") != std::string::npos)
        return 0;

    int msg_length = msg.length();
    int count = 1;
    for(int i = 2; i <= msg_length; i ++)
    {
        if(msg[i - 2 ] == '1' || (msg[i - 2] == '2' && msg[i - 1] < '7'))
        {
            count++;
        }
    }

    return count;
}

int main ()
{
    std::cout<<"Daily Coding Problem 7"<<std::endl;

    std::string msg = "1234";

    std::cout<<possible_decode_ways(msg)<<std::endl;
    return 0;
}