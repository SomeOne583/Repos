calculos = [ [ -1 for i in range(1001) ] for j in range(1001) ]

def solve(n, l):
        if (calculos[n][l] == -1):
                if (n > 9 * l):
                        calculos[n][l] = 0
                elif (l == 1):
                        calculos[n][l] = 1
                else:
                        acum = 0
                        for i in range(n, max(0, n - 9) - 1, -1):
                                acum += solve(i, l - 1)
                        calculos[n][l] = acum
        return calculos[n][l]

k = int(input())
e = input()
e = e.split(" ")
for i in range(k):
        N = int(e[i])
        print(solve(N, N))