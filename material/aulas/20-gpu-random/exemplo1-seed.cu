#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/constant_iterator.h>
#include <thrust/random/uniform_real_distribution.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random.h>

int main() {    
    int seed = 0;
    if(getenv("SEED")){
        seed = atoi(getenv("SEED"));
    }

    // create a new minstd_rand from a seed
    thrust::default_random_engine rng(seed);

    for(int i  = 0; i < 10; i++){
    // create a uniform_real_distribution to produce floats from [25,40)
        thrust::uniform_real_distribution<float> dist(25,40);
        std::cout << "Numero aleatório: " << dist(rng) << "\n";
    }


}
