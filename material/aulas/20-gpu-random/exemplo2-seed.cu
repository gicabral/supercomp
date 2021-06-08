#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/constant_iterator.h>
#include <thrust/iterator/counting_iterator.h>
#include <thrust/random/uniform_real_distribution.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random.h>

struct rng_gpu{
    thrust::default_random_engine eng;
    thrust:: uniform_real_distribution<float> d;

    __device__ __host__
    double operator()(const int &i){
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
    thrust::uniform_real_distribution<float> dist(25,40);

    rng_gpu rc = {.eng = rng, .d = dist};  
    thrust::device_vector<double> D(10);
    thrust::transform(thrust::make_counting_iterator<int>(0),
                    thrust::make_counting_iterator<int>(10), 
                    D.begin(), rc);

    for(int i = 0; i < 10; i++){
        std::cout << D[i] << "\n";
    }                




}
