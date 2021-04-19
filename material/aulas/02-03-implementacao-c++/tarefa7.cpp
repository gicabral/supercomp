#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

void calcula_distancias(std::vector<double> *X, std::vector<double> *Y, std::vector<std::vector<double>> *D){
    int n = (*X).size();
    for(int i = 0; i < n; i++){
        std::vector<double>linha; // RECRIADO TODA ITERAÇÃO
        for(int j = 0; j < n; j++){
            double DX = (*X)[i] - (*X)[j];
            double DY = (*Y)[i] - (*Y)[j];
            double dist = sqrt(DX*DX + DY*DY);
            linha.push_back(dist);
        }
        (*D).push_back(linha);
    }

}
int main()
{
    int n;
    std::cin >> n;
    std::vector<double> X(n), Y(n);
    std::vector<std::vector<double>> D;

    for(int i = 0; i < n; i++){
        std::cin >> X[i] >> Y[i];
    }

    calcula_distancias(&X, &Y, &D);

    std::cout << std::setprecision(2) << std::fixed;
    for(auto linha : D){
        for (auto el : linha){
            std::cout<< el << " ";
        }
        std::cout << "\n";
    }

    return 0;
}