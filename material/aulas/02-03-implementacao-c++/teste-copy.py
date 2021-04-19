import subprocess
import time
import os, os.path
import matplotlib.pyplot as plt
import numpy as np
 

def roda_com_entrada(executavel, arquivo_in):
    tempo = []
    with open(arquivo_in) as f:
        start = time.perf_counter()
        proc = subprocess.run(['./' + executavel],
                              input=f.read(),
                              text=True,
                              capture_output=True)
        end = time.perf_counter()

        # print('Saida:', proc.stdout)
        # print('Stderr:', proc.stderr)
        # print('Tempo total(s):', end - start)
    tempo.append(float(end-start))
    return tempo 

def get_size(arquivo_in):
    tamanho = []
    with open(arquivo_in, "r") as f:
        lines = f.readlines()    
        tamanho.append(int(lines[0]))
    print(tamanho)
    return tamanho 


i = 0
tam = []
r1 = []
r2 = []
r1_par = []
r2_par = []
r3_par = []
while i < 5:
    r1.append(roda_com_entrada("e-saida", f"t6-in-{i}.txt"))
    r2.append(roda_com_entrada("e-saida", f"t6-in-{i}.txt"))
    r1_par.append(roda_com_entrada("e-saida", f"t6-in-{i}.txt"))
    r2_par.append(roda_com_entrada("e-saida", f"t6-in-{i}.txt"))
    r3_par.append(roda_com_entrada("e-saida", f"t6-in-{i}.txt"))
    tam.append(get_size(f"t6-in-{i}.txt"))
    i+=1

plt.plot(tam, r1, "-b", label="in0")
plt.plot(tam, r1_par, "-r", label="in1")
plt.plot(tam, r2, "-g", label="in2")
plt.plot(tam, r2_par, "-y", label="in3")
plt.plot(tam, r3_par, "-y", label="in4")
plt.legend(loc="upper left")
plt.xlabel("Length of the file (number of lines)")
plt.ylabel("Time taken (seconds)")
plt.savefig('grafico')

