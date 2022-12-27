#include <iostream>
#include <random>
#include <iomanip>

struct Vector2
{
    Vector2(): x(0), y(0) {};
    double x;
    double y;
};

bool is_in_circle(Vector2 point, double radius)
{
    return point.x * point.x + point.y * point.y <= radius * radius;
}

std::random_device rd;  
std::mt19937 gen(rd()); 

template <typename T>
T generate_random_number(T from, T to)
{
    std::uniform_int_distribution<> distrib(from, to);

    return distrib(gen);
}

double estimated_pi(int precision)
{
    double pi = 0.0;

    double radius = 1.0;
    Vector2 generated_point;

    int generated_points_amount = 0;
    int generated_circle_points_amount = 0;

    for(int i = 0; i < precision; i++)
    {
        generated_point.x = generate_random_number(0.0, (double)precision) / precision * radius;
        generated_point.y = generate_random_number(0.0, (double)precision) / precision * radius;

        generated_points_amount++;
        if(is_in_circle(generated_point, radius))
            generated_circle_points_amount++;
    }

    std::cout<<generated_circle_points_amount<<" | "<<generated_points_amount<<std::endl;
    pi = (double)generated_circle_points_amount / generated_points_amount * 4;

    return pi;
}

int main()
{
    std::cout<<"Daily Coding Problem 14"<<std::endl;

    std::cout << std::fixed << std::setprecision(3);
    std::cout<<estimated_pi(10000)<<std::endl;

    return 0;
}