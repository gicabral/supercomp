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

int main()
{
    int n, maxWeight;
    std::cin >> n >> maxWeight;
    std::vector<struct Objects> objects(n);
    std::vector<int> mochila; 
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

    int peso_atual = 0;
    int valor = 0;
    int iter = 0;
    bool passou = false;

    while(iter <= 10){
        for(auto &obj: objects){
            double rnd_num = distribution(generator);
            int selectedItemPos = randomItemPos(generator);

            if(usados[selectedItemPos] == false && rnd_num <= 0.25 && passou == false){
                usados[selectedItemPos] = true;
                peso_atual += objects[selectedItemPos].weigth;
                valor += objects[selectedItemPos].value;
                passou = true;
            }

            if(peso_atual + obj.weigth <= maxWeight && usados[obj.id] == false && rnd_num <= 0.75){
                usados[obj.id] = true;
                peso_atual += obj.weigth;
                valor += obj.value;
            }
        }
        std::sort(mochila.begin(), mochila.end());

        std::cout << peso_atual << " " << valor << " "<< "0" << "\n";
        for(int i = 0; i < n; i ++){
            if(usados[i]){
                std::cout << i << " ";
            }
        }
        std::cout << "\n";
        iter++;
    }    

    return 0;
}