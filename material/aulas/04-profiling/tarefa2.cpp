#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

void calcula_distancias(std::vector<double> &X, std::vector<double> &Y, std::vector<double> &D){
    int n = X.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            //vou preencher as duas posições ao mesmo tempo
            //começo o j de i, para não rodar muitas coisas e não precisar do if
            double DX = X[i] - X[j];
            double DY = Y[i] - Y[j];
            double dist = sqrt(DX*DX + DY*DY);
            D[j*n + i] = D[i*n +j] = dist;
        }
    }

}
int main()
{
    int n;
    std::cin >> n;
    std::vector<double> X(n), Y(n);
    std::vector<double> D(n*n, 0);

    for(int i = 0; i < n; i++){
        std::cin >> X[i] >> Y[i];
    }

    calcula_distancias(X, Y, D);

    std::cout << std::setprecision(2) << std::fixed;
    for(const auto &el : D){
        std::cout<< el << " ";
    }
    std::cout << "\n";
    

    return 0;
}