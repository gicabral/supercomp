#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    // double *x = new double[n];

    std::vector<double> x;
    double nx = 0;
    for(int i = 0; i < n; i++){
        //std::cin >> x[i];
        std::cin >> nx;
        x.push_back(nx);
    }
    
    double U = 0;
    double sigma = 0;
    for (int i = 0; i < n; i++)
    {
        U +=x[i];
    }
    U /= n;
    for(int i = 0; i < n; i++){
        sigma += std::pow((x[i] - U), 2);
    }
    sigma /= n;
    std::cout << "U:" << std::setprecision(10) << U << "\n" <<"Sigma:" << std::setprecision(10) << sigma << "\n";

    // delete[] x;
    return 0;
}