#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct Objects{
    int id, value, weigth;

    bool operator<(Objects &a)
    {
        return weigth < a.weigth;
    }
};


int main()
{
    int n, maxWeight;
    std::cin >> n >> maxWeight;
    std::vector<struct Objects> objects(n);
    std::vector<int> mochila; 

    for(int i =0; i < n; i++){
        objects[i].id = i;
        std::cin >> objects[i].weigth >>  objects[i].value;
    }

    std::sort(objects.begin(), objects.end());

    int peso_atual = 0;
    int valor = 0;

    for(auto &obj: objects){
        if(peso_atual + obj.weigth <= maxWeight){
            mochila.push_back(obj.id);
            peso_atual += obj.weigth;
            valor += obj.value;
        }
    }

    std::sort(mochila.begin(), mochila.end());

    std::cout << peso_atual << " " << valor << " "<< "0" << "\n";
    for(int id: mochila){
        std::cout << id << " ";
    }
    std::cout << "\n";
    

    return 0;
}