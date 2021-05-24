#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <omp.h>



int main()
{
    int N = 10000000;
    double sum = 0;
    int seed = 1000;
    // double rnd_numX, rnd_numY;
    // std::vector<std::vector<double>> vec(nthreads);
    std::vector<double> par;
    if(getenv("SEED")){
        seed = atoi(getenv("SEED"));
    }

    //seq -> tempo : 0m0.288s, valor: 3.1417
    // par -> tempo : 0m2.214s, valor: 3.1417
    // par2 -> tempo : 0m0.043s, valor: 3.14161

    // 
    #pragma omp parallel default(none) shared(sum) firstprivate(N, seed)
    {
        int thread_atual = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        std::default_random_engine generator(thread_atual*seed);
        std:: uniform_real_distribution<double> distribution(0, 1);

        long chunk_size = N/nthreads;
        long start = thread_atual*chunk_size;
        long end = (thread_atual + 1)*chunk_size;
        if(end > N) end = N;

        double local_sum = 0;
        for(int i = start; i < end; i++){
            double x = distribution(generator);
            double y = distribution(generator);
            if(std::pow(x,2) + std::pow(y,2) <= 1){
                local_sum++;
            }

        }
        #pragma omp critical
            sum +=local_sum;
    }
    
    // rnd_numX = distribution(generator);
    // rnd_numY = distribution(generator);
    // vec[thread_atual].push_back(rnd_numX);
    // vec[thread_atual].push_back(rnd_numY);


    // #pragma omp parallel for reduction (+:sum) private(nthreads, rnd_numX, rnd_numY)    
    

    double pi = 4*sum/N;

    std::cout <<"pi = " << pi << std::setprecision(15);

    // std::cout << vec[0][0] << " ";
    
    std::cout << "\n";


    return pi;
}