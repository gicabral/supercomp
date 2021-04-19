#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>

void printa_vetor(int n, double nx){
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
    double media = 0;
    double var = 0;

    std::vector<double> x;
    double nx = 0;
    for(int i = 0; i < n; i++){
        std::cin >> nx;
        x.push_back(nx);
    }

    for(int i = 1; i < n; i++){
        media += x[i];
    }
    media /= n;

    for(int i = 1; i < n; i++){
        var += std::pow(x[i]-media, 2);
    }
    var /= n;

    std::cout << "Média " << std::setprecision(10)<< media << "\n" << "Variância " << std::setprecision(10) << var << "\n";
    printa_vetor(n, nx);

    return 0;

}