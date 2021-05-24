import numpy as np
import numpy.random

n, m = 10, 3
V = np.random.random((n, m))
print(n,m)
for i in range(V.shape[0]):
    print(*V[i])