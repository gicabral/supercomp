#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

struct Object
{
    int id, peso, valor;
};

struct Solucao
{
    std::vector<bool>usado;
    int peso, valor;
    
    Solucao(int N){
        usado.resize(N, false);
        valor = peso = 0;
    }
};

long num_copy = 0;
long num_leaf = 0;

int busca_exaustiva(std::vector<Object> &obj, int C, Solucao &melhor, Solucao &atual, long unsigned int i = 0){
    if(i == obj.size()){
        num_leaf++;
        if(atual.valor > melhor.valor){
            melhor = atual;
            num_copy++;
        }
        return 0;
    }

    atual.usado[i] = false;
    int sem = busca_exaustiva(obj, C, melhor, atual, i+1);

    int com = 0;
    if(obj[i].peso <= C){
        atual.usado[i] = true;
        atual.valor += obj[i].valor;
        atual.peso += obj[i].peso;
        com = obj[i].valor + busca_exaustiva(obj, C - obj[i].peso, melhor, atual, i+1);
        atual.usado[i] = false;
        atual.valor -= obj[i].valor;
        atual.peso -= obj[i].peso;
    }

    return std::max(com, sem);
}
int main()
{
    auto start = std::chrono::steady_clock::now();
    int n, maxWeight;
    std::cin >> n >> maxWeight;
    std::vector<struct Object> objects(n);

    for (int i = 0; i < n; i++)
    {
        objects[i].id = i;
        std::cin >> objects[i].peso >> objects[i].valor;
    }

    Solucao melhor(n);
    Solucao atual(n);
    busca_exaustiva(objects, maxWeight, melhor, atual);

    std::cout << melhor.peso << " " << melhor.valor << " 1" << "\n";
    for(int i = 0; i < n; i++){
        if(melhor.usado[i]){
            std::cout << i << " ";
        }
    }

    std::cout << "\n";
    std::cerr << "num_copy " << num_copy << "\n";
    std::cerr << "num_leaf " << num_leaf << "\n";

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";


    return 0;
}