#include <iostream>
#include <chrono>

int main(){
    auto start = std::chrono::steady_clock::now();
    int n;
    std::cin >> n;
    double b = double (n)/2;
    std::cout << "Saída " << b << "\n";  
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}


