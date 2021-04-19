import random
import numpy as np
import sys

n_objetos = int(sys.argv[1])
capacidade = int(sys.argv[2])
print(n_objetos, capacidade)

for i in range(n_objetos):
    objetos = np.random.permutation(n_proj)
    print(' '.join([str(choices[c]) for c in range(n_escolhas) ]))