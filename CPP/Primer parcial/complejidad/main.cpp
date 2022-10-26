#include <iostream>
using namespace std;

int main() {
        int c = 0, n;

        cout << "Ingresa el tamaño del arreglo: ";
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) {
                cout << "Ingresa el entero " << i + 1 << ": ";
                cin >> arr[i];
        }


        for (int i = 0; i < *(&arr + 1) - arr; i++)     // Como el tamaño del arreglo funciona como n sería O(n)
                if (arr[i] % 2 == 1)                    // Toma la complejidad de la condicional que es O(1)
                        c += arr[i];                    // Esto es complejidad constante O(1)
                                                        // La complejidad del ciclo sería O(n)

        cout << "La suma de los números impares en el arreglo es: " << c;
        return 0;
}