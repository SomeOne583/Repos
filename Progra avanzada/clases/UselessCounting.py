cant = 0
factoriales = [ -1 for i in range(100) ]

def factorial(n):
        if (factoriales[n] == -1):
                factoriales[n] = n * factorial(n - 1)
        return factoriales[n]

def solve(actual, index, acum, N):
        if (acum == N):
                global cant
                perms = factorial(N) // factorial(N - len(actual))
                repeticiones = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
                for i in actual:
                        repeticiones[int(i)]+=1
                for i in range(1, 10):
                        perms //= factorial(repeticiones[i]);
                cant += perms;
        else:
                for i in range(index, 10):
                        if (acum + i <= N):
                                solve(actual + chr(48 + i), i, acum + i, N);

factoriales[0] = 1
e = input()
e = e.split(" ")
k = int(e[0])
for i in range(k):
        N = int(e[i + 1])
        cant = 0
        if (N == 1):
                cant += 1
        solve("", 1, 0, N)
        print(cant)