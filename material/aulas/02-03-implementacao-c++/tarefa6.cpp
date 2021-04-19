#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<double> X(n), Y(n);
    std::vector<std::vector<double>> D;
    double DX;
    double DY;
    double dist;

    for(int i = 0; i < n; i++){
        std::cin >> X[i] >> Y[i];
    }
    
    for(int i = 0; i < n; i++){
        std::vector<double>linha; // RECRIADO TODA ITERAÇÃO
        for(int j = 0; j < n; j++){
            DX = X[i] - X[j];
            DY = Y[i] - Y[j];
            dist = sqrt(DX*DX + DY*DY);
            linha.push_back(dist);
        }
        D.push_back(linha);
    }

    std::cout << std::setprecision(2) << std::fixed;
    for(auto linha : D){
        for (auto el : linha){
            std::cout<< el << " ";
        }
        std::cout << "\n";
    }
    return 0;
}