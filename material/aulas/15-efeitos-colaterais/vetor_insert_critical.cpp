#include <vector>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

double conta_complexa(int i) {
	sleep(1);
	return 2 * i;
}

int main() {
	int N = 10; 
	std::vector<double> vec;
	// só com o parallel for da erro, por causa do push_back
	// sempre que tem variáveis compartilhadas é perigoso
	
	//Esse aqui chama a conta_complexa na parte critica tbm, o que demora
	// #pragma omp parallel for default(none) shared(vec) firstprivate(N)
	// for (int i = 0; i < N; i++) {
	// 	#pragma omp critical
	// 	{
	// 		vec.push_back(conta_complexa(i));
	// 	}
	// }

	#pragma omp parallel for default(none) shared(vec) firstprivate(N)
	for (int i = 0; i < N; i++) {
		int conta = conta_complexa(i);
		#pragma omp critical
		{
			vec.push_back(conta);
		}
	}
	

	
	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << " ";
	}
	
	return 0;
}
