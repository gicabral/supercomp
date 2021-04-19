#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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

long int num_copy = 0;
long int num_leaf = 0;
long int num_bound = 0;
std::vector<long> nivel_bound;

void busca_exaustiva(std::vector<Object> &obj, int C, int valor_otimista, Solucao &melhor, Solucao &atual, long unsigned int i = 0){
    if(i == obj.size()){
        num_leaf++;
        if(atual.valor > melhor.valor){
            melhor = atual;
            num_copy++;
        }
        return;
    }
    int bound = valor_otimista + atual.valor;
    if(bound <= melhor.valor){
        num_bound++;
        nivel_bound[i]++;
        return;
    }
    // 

    if(obj[i].peso <= C){
        atual.usado[i] = true;
        atual.valor += obj[i].valor;
        atual.peso += obj[i].peso;
        busca_exaustiva(obj, C - obj[i].peso, valor_otimista - obj[i].valor, melhor, atual, i+1);
        atual.usado[i] = false;
        atual.valor -= obj[i].valor;
        atual.peso -= obj[i].peso;
    }
    atual.usado[i] = false;
    busca_exaustiva(obj, C, valor_otimista - obj[i].valor, melhor, atual, i+1);
}
int main()
{
    int n, maxWeight;
    std::cin >> n >> maxWeight;
    std::vector<struct Object> objects(n);

    int valor_otimista = 0;

    for (int i = 0; i < n; i++)
    {
        objects[i].id = i;
        std::cin >> objects[i].peso >> objects[i].valor;
        valor_otimista += objects[i].valor;
    }

    nivel_bound.resize(n, 0);

    Solucao melhor(n);
    Solucao atual(n);
    busca_exaustiva(objects, maxWeight, valor_otimista, melhor, atual);

    std::cout << melhor.peso << " " << melhor.valor << " 1" << "\n";
    for(int i = 0; i < n; i++){
        if(melhor.usado[i]){
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
    
    for(auto &b: nivel_bound){
        std::cout << b << " ";
    }

    std::cout << "\n";
    std::cerr << "num_copy " << num_copy << "\n";
    std::cerr << "num_leaf " << num_leaf << "\n";
    std::cerr << "num_bound " << num_bound << "\n";



    return 0;
}