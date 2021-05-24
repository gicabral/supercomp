#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>


int main()
{
    int N = 10000000;
    double sum = 0;
    int seed = 1000;
    if(getenv("SEED")){
        seed = atoi(getenv("SEED"));
    }

    std::default_random_engine generator(seed);
    std:: uniform_real_distribution<double> distribution(0, 1);

    for(int i = 0; i < N; i++){
        double rnd_numX = distribution(generator);
        double rnd_numY = distribution(generator);

        if(std::pow(rnd_numX,2) + std::pow(rnd_numY,2) <= 1){
            sum +=1;
        }

    }

    double pi = 4*sum/N;

    std::cout <<"pi = " << pi << std::setprecision(15);


    return pi;
}