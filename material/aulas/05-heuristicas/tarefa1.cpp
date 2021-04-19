#include <iostream> // std::cout, std::fixed
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

struct object{
    int id;
    int peso;
    int valor;
};

bool ordena_objetos(object a, object b){
    return a.valor > b.valor;
}

int main(){
    int N, peso_max;
    std::cin >> N >> peso_max;
    std::vector<object> objetos(N);
    std::vector<int> mochila;
    
    for(int i = 0; i<N; i++){
        std::cin >> objetos[i].peso >> objetos[i].valor;
        objetos[i].id = i;
    }

    std::sort(objetos.begin(), objetos.end(), ordena_objetos);

    int peso_atual = 0;
    int valor_atual = 0;
    for(auto &obj : objetos){
        if(peso_atual + obj.peso <= peso_max){
            peso_atual += obj.peso;
            valor_atual += obj.valor;
            mochila.push_back(obj.id);
        }
    }

    std::cout << peso_atual << " " << valor_atual << "\n";
    for(int id: mochila){
        std::cout << id << " ";
    }
    std::cout << "\n";

    return 0;
}

