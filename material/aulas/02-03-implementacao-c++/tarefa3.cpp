#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    double S = 0;
    for (int i = 0; i < n; i++)
    {
        S += 1 / (std::pow(2, i));
    }
    std::cout << "Saída:" << std::setprecision(15) << S << "\n";
}