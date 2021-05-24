#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

struct Vetor{
    int id;
    std::vector<double>valores;
};

void distancia_euclidiana(std::vector<std::vector<double>> &vec, int n, int m, std::vector<struct Vetor> V){
    double dist = 0;
    for (int i = 0; i < n; i++) {
        std::vector<double> linha;
        for(int j = 0; j < n; j++){
            for (int k = 0; k < m; k++) {
                dist += std::pow(V[i].valores[k] - V[j].valores[k], 2); 
            }
            dist = std::sqrt(dist);
            linha.push_back(dist); 
            dist = 0;  
        }
        vec.push_back(linha);
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<double>> vec;
    std::vector<struct Vetor> V(n);
    double temp;

    for(int i = 0; i < n; i++){
        V[i].id = i;
        for(int j = 0; j < m; j++){
           std::cin >> temp;
           V[i].valores.push_back(temp);
        }
    }

    distancia_euclidiana(vec, n, m, V);

    
    std::cout << std::setprecision(6)<< std::fixed;
    for(auto linha: vec){
        for(auto el: linha){
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    return 0;

}