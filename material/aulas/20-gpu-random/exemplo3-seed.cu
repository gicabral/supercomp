#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/counting_iterator.h>
#include <thrust/random/uniform_real_distribution.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random.h>

struct rng_gpu{
    int SEED;

    __device__ __host__
    double operator()(const int &i){
        thrust::default_random_engine eng(SEED);
        thrust:: uniform_real_distribution<double> d(25,40);

        eng.discard(100);
        return d(eng);
    }
};

int main() {    
    int seed = 0;
    if(getenv("SEED")){
        seed = atoi(getenv("SEED"));
    }

    // create a new minstd_rand from a seed
    thrust::default_random_engine rng(seed);
    // create a uniform_real_distribution to produce floats from [25,40)
    thrust::uniform_real_distribution<double> dist(25,40);

    rng_gpu rc = {.SEED = seed};  
    thrust::device_vector<double> D(10);
    thrust::transform(thrust::make_counting_iterator<int>(0),
                    thrust::make_counting_iterator<int>(10), 
                    D.begin(), rc);

    for(int i = 0; i < 10; i++){
        std::cout << D[i] << "\n";
    }                




}
