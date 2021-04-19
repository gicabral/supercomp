#include <iostream>
#include <math.h> 
#include <iomanip>

int main(){
    int n;
    std::cin >> n;
    double S = 0;
    for(int i = 0; i <n; i++){
        S += 1/pow(2, i);
    }

    std::cout << std::setprecision(15) << S;
}