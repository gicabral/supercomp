#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/constant_iterator.h>

int main() {
    thrust::device_vector<double> AAPL;
    thrust::device_vector<double> MSFT;
    
    double stocks_AAPL, stocks_MSFT, mean, var;

    while(std::cin){
        std::cin >> stocks_AAPL >> stocks_MSFT;
        AAPL.push_back(stocks_AAPL);
        MSFT.push_back(stocks_MSFT);
    }

    int N = AAPL.size();
    thrust::device_vector<double> MEAN_DIF(N);

    thrust::transform(AAPL.begin(), AAPL.end(), MSFT.begin(), MEAN_DIF.begin(), thrust::minus<double>());
    double val = thrust::reduce(MEAN_DIF.begin(), MEAN_DIF.end());
    mean = val/2517;
    std::cout << "Média: " << fabs(mean) << "\n";

    // thrust::device_vector<double> MV(N, mean);
    thrust::device_vector<double> MV_DIF(N);

    thrust::transform(MEAN_DIF.begin(), MEAN_DIF.end(), thrust::constant_iterator<double>(mean), MV_DIF.begin(), thrust::minus<double>());
    // thrust::transform(MEAN_DIF.begin(), MEAN_DIF.end(), MV.begin(), MV_DIF.begin(), thrust::minus<double>());
    thrust::transform(MV_DIF.begin(), MV_DIF.end(), MV_DIF.begin(), MV_DIF.begin(), thrust::multiplies<double>());
    double val2 = thrust::reduce(MV_DIF.begin(), MV_DIF.end());
    var = val2/N;
    std::cout << "Variância: " << var << "\n";

}
