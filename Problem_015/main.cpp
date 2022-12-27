#include <iostream>
#include <random>
#include <vector>

std::random_device rd;  
std::mt19937 gen(rd()); 

template <typename T>
T generate_random_number(T from, T to)
{
    std::uniform_int_distribution<> random(from, to);

    return random(gen);
}

template <typename T>
std::vector<T> get_random_element(std::vector<T> stream,int random_element_amount)
{
    std::vector<T> resevoir;

    int i = 0;
    for( ; i < random_element_amount; i ++)
    {
        resevoir.push_back(stream.at(i));
    }

    for(; i < stream.size(); i ++)
    {
        int random_number = generate_random_number(0, i);
        if(random_number < random_element_amount)
        {
            resevoir.at(random_number) = stream.at(i);
        }

    }

    return resevoir;
}

template <typename T>
void print_vector_data(std::vector<T> stream)
{
    for(auto i = stream.begin(); i != stream.end(); i ++)
    {
        std::cout<< *i << " ";
    }
    std::cout<<std::endl;
}

int main ()
{
    std::cout<<"Daily Coding Problem 15"<<std::endl;

    std::vector<int> data = {1,2,3,4,5,6,7,8,9,10,11,12};
    std::vector<int> result = get_random_element(data,1);

    print_vector_data(result);


    return 0;
}