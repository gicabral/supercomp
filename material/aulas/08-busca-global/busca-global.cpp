#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct Objects{
    int id, value, weight;
};

struct Solucao
{
    std::vector<bool>usado;
    int weight, value;
    
    Solucao(int N){
        usado.resize(N, false);
        value = weight = 0;
    }
};

long num_copy = 0;

int busca_exaustiva(int n, int maxWeight, Solucao &melhor, Solucao &atual, std::vector<struct Objects> objects, long unsigned int i = 0){
    if(i == objects.size()){
        if(atual.value > melhor.value){
            melhor = atual;
            num_copy++;
        }
        return 0;
    }

    int com = 0;
    if(objects[i].weight <= maxWeight){
        atual.value += objects[i].value;
        atual.usado[i] = true;
        atual.weight += objects[i].weight;
        com = busca_exaustiva(n, maxWeight - objects[i].weight, melhor, atual, objects, i+1);
        atual.value -= objects[i].value;
        atual.usado[i] = false;
        atual.weight -= objects[i].weight;
    }

    atual.usado[i] = false;

    int sem = busca_exaustiva(n, maxWeight, melhor, atual, objects, i+1);

    return std::max(com, sem);  

}

int main()
{
    int n, maxWeight;
    std::cin >> n >> maxWeight;
    std::vector<struct Objects> objects(n);
    std::vector<bool> usados(n, false);
    std::vector<bool> melhor_usados(n, false);

    for(int i =0; i < n; i++){
        objects[i].id = i;
        std::cin >> objects[i].weight >>  objects[i].value;
    }

    Solucao melhor(n);
    Solucao atual(n);

    busca_exaustiva(n, maxWeight, melhor, atual, objects);  

    std::cout << melhor.weight << " " << melhor.value << " "<< "1" << "\n";
    for(int i = 0; i < n; i ++){
        if(melhor.usado[i]){
            std::cout << i << " ";
        }
    }
    std::cout << "\n";  
    std::cerr << "numcopy " << num_copy << "\n"; 

    return 0;
}