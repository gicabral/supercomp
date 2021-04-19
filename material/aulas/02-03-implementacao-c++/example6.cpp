#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

void printa_vetor(int n){
    std::vector<double> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(i*i);
    }
    std::cout << "Tamanho do vetor: " << vec.size() << "\n";
    std::cout << "Primeiro elemento: " << vec.front() << "\n";
    std::cout << "Último elemento: " << vec.back() << "\n";
    std::cout << "Elemento 3: " << vec[2] << "\n";
}

int main(){
    int n;
    std::cin >> n;
    double dist = 0;
    std::vector<std::vector<double>> vec;
    std::vector<double> X(n), Y(n);

    for(int i = 0; i < n; i++){
        std::cin >> X[i] >> Y[i];
    }

    for(int i = 0; i < n; i++){
        std::vector<double>linha;
        for(int j = 0; j < n; j++){
            dist = std::sqrt(std::pow(X[i] - X[j], 2) + std::pow(Y[i] - Y[j], 2));
            linha.push_back(dist);
        }
        vec.push_back(linha);
    }

    std::cout << std::setprecision(10)<< std::fixed;
    for(auto linha: vec){
        for(auto el: linha){
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;

}