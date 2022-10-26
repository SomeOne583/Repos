// Matricula: 577441
// Nombre: Jan Carlo Reyes Martínez
// Doy mi palabra de que he realizado esta actividad con integridad académica
#include <iostream>

using namespace std;

// Complejidad: O(1)
int sumaRecursivaCuadrada(int n) {
        if (n == 1)
                return 1;
        else
                return n * n + sumaRecursivaCuadrada(n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << sumaRecursivaCuadrada(n) << endl;
}