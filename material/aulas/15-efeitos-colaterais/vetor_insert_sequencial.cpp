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
	
	for (int i = 0; i < N; i++) {
		vec[i] = conta_complexa(i);
	}

	
	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << " ";
	}
	
	return 0;
}
