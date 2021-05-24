#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/constant_iterator.h>

int main() {
    thrust::device_vector<double> AAPL;    
    double stocks_AAPL, stocks_MSFT, mean, var;

    while(std::cin){
        std::cin >> stocks_AAPL;
        AAPL.push_back(stocks_AAPL);
    }

    int N = AAPL.size();
    thrust::device_vector<double> ganho_diario(N-1);

    thrust::transform(AAPL.begin()+1, AAPL.end(), AAPL.begin(), ganho_diario.begin(), thrust::minus<double>());
    
    printf("Ganho: ");
    for (thrust::device_vector<double>::iterator i = ganho_diario.begin(); i != ganho_diario.end(); i++) {
        std::cout << *i << " ";
    }
    printf("\n");

}
