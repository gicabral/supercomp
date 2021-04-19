#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

void calcula_distancias(std::vector<std::vector<double>> &vec, int n, std::vector<double> &X, std::vector<double> &Y){
    double dist = 0;
    for(int i = 0; i < n; i++){
        std::vector<double>linha;
        for(int j = 0; j < n; j++){
            dist = std::sqrt(std::pow(X[i] - X[j], 2) + std::pow(Y[i] - Y[j], 2));
            linha.push_back(dist);
        }
        vec.push_back(linha);
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> vec;
    std::vector<double> X(n), Y(n);

    for(int i = 0; i < n; i++){
        std::cin >> X[i] >> Y[i];
    }

    calcula_distancias(vec, n, X, Y);

    
    std::cout << std::setprecision(10)<< std::fixed;
    for(auto linha: vec){
        for(auto el: linha){
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;

}