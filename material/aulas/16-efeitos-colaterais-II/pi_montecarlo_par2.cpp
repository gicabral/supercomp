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

    //seq -> tempo : 0m0.288s, valor: 3.1417
    // par -> tempo : 0m2.214s, valor: 3.1417
    // par2 -> tempo : 0m0.043s, valor: 3.14161


    #pragma omp parallel for reduction (+:sum)
    for(int i = 0; i < N; i++){
        std::default_random_engine generator(seed);
        std:: uniform_real_distribution<double> distribution(0, 1);
        seed = 100*i;
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