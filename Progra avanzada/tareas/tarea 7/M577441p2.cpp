// Juan Manuel Cuevas Gaytan 611978
// Jan Carlo Reyes Martínez 577441
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica
// Problema 2 Useless Counting

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

// Memorización
unsigned long long calculos[21][21];

// Función recursiva que me dice de cuantas formas puedo escribir números que sumen n con l digitos
unsigned long long solve(int n, int l) {
        // Checho si ya esta calculado
        if (calculos[n][l] == -1) {
                // Un caso base para números que no puedo representar como:
                // - 10 en 1 digito
                // - 19 en 2 digitos
                // - 28 en 3 digitos
                // - cualquier n mayor que 9 * l
                if (n > 9 * l) {
                        calculos[n][l] = 0;
                // Otro caso base, aquí llegaría cuando n sea entre 0 y 9 y l valga 1, así que solo
                // hay una forma de expresarlo
                } else if (l == 1) {
                        calculos[n][l] = 1;
                } else {
                        // Creo una variable para guardar el acumulado
                        unsigned long long acum = 0;
                        // Decidiendo la condicional a usar
                        // n - i >= 0
                        // n - i > -1
                        // n > i - 1
                        // n + 1 > i
                        // i < n + 1
                        for (int i = 0; i <= 9 && i < n + 1; i++) {
                                acum += solve(n - i, l - 1);
                        }
                        calculos[n][l] = acum;
                }
        }
        // Se regresa lo que esta memorizado, ya sea que se calculo ahorita o ya estaba
        return calculos[n][l];
}

int main() {
        int N, k;
        // Se llena la memorización de -1
        memset(calculos, -1, sizeof(calculos));

        cin >> k;

        while (k--) {
                cin >> N;
                // N = 1 es un caso especial porque solo en el cuenta 10^N
                if (N == 1) {
                        cout << "2\n";
                } else {
                        cout << solve(N, N) << "\n";
                }
        }
        
        return 0;
}
