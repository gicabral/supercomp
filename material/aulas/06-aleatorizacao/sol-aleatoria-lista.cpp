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
        return value > a.value;
    }
};

void objs_aleatorios(int n, int maxWeight, std::vector<bool> usados, std::default_random_engine generator, std::uniform_int_distribution<int> randomItemPos, std::vector<struct Objects> objects){
    int peso_atual = 0;
    int valor = 0;

    for(int i = 0; i < n; i++){
        int rnd_num = randomItemPos(generator);
        if(peso_atual + objects[rnd_num].weigth <= maxWeight && usados[objects[rnd_num].id] == false){
                peso_atual += objects[rnd_num].weigth;
                valor += objects[rnd_num].value;
                usados[objects[rnd_num].id] = true;
        }
    }

    std::cout << peso_atual << " " << valor << " "<< "0" << "\n";
    for(int i = 0; i < n; i ++){
        if(usados[i]){
            std::cout << i << " ";
        }
    }
    std::cout << "\n";   

}

int main()
{
    int n, maxWeight;
    std::cin >> n >> maxWeight;
    std::vector<struct Objects> objects(n);
    std::vector<bool> usados(n, false);

    for(int i =0; i < n; i++){
        objects[i].id = i;
        std::cin >> objects[i].weigth >>  objects[i].value;
    }

    std::sort(objects.begin(), objects.end());

    int seed = 10;
    if(getenv("SEED")){
        seed = atoi(getenv("SEED"));
    }

    std::default_random_engine generator(seed);
    std:: uniform_real_distribution<double> distribution(0, 1);
    std::uniform_int_distribution<int> randomItemPos(0, n - 1);

    objs_aleatorios(n, maxWeight, usados, generator, randomItemPos, objects);    

    return 0;
}