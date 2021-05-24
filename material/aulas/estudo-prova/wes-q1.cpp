#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std;


double calcdist(double a[], double b[], int m){
    double sum = 0;
    for(int k = 0; k < m; k++){
        sum+= (a[k]-b[k])*(a[k]-b[k]);
    }
    
    return sqrt(sum);
}


int main(){

    int n,m;
    string line;
    cin >> n >> m;
    double in_matr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            double a;
            cin >> a;
            in_matr[i][j] = a;
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    double dists[n][n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            dists[i][j] = calcdist(in_matr[i], in_matr[j], m);
        }
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::microseconds> (end_time - start_time);
    std::cerr << runtime.count();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dists[i][j] << ' ';
        }
        cout << '\n';
    }

}