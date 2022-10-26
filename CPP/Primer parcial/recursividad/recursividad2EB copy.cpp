#include <iostream>
using namespace std;

int contarPares(int nums[], int n) {
        if (n == 0)
                return (nums[0] % 2 == 0) ? 1 : 0;
        else
                return contarPares(nums, n - 1) + ((nums[n] % 2 == 0) ? 1 : 0);
}

bool revisarPares(int n) {
        if (n < 10)
                return n % 2 == 0;
        else
                return revisarPares(n / 10) * (n % 2 == 0);
}

int encontrarMayor(int nums[], int n) {
        if (n == 1)
                return (nums[1] > nums[0] ? nums[1] : nums[0]);
        else {
                int t = encontrarMayor(nums, n - 1);
                return (nums[n] > t) ? nums[n] : t;
        }
}

int encontrarElemento(int nums[], int num) {
        
}

int main() {
        cout << "\n\n---------- 1 ----------\n\n";
        int n;
        cout << "Ingresa el tamaño del arreglo: ";
        cin >> n;

        int nums[n];
        for (int i = 0; i < n; i++) {
                cout << "Ingresa el entero " << i + 1 << ": ";
                cin >> nums[i];
        }

        cout << "El arreglo tiene " << contarPares(nums, n - 1) << " números pares";

        cout << "\n\n---------- 2 ----------\n\n";

        cout << "Ingresa el número entero: ";
        cin >> n;

        if (revisarPares(n))
                cout << "El número " << n << " tiene todos sus digitos pares";
        else
                cout << "El número " << n << " no tiene todos sus digitos pares";

        cout << "\n\n---------- 3 ----------\n\n";

        cout << "Ingresa el tamaño del arreglo: ";
        cin >> n;

        int nums2[n];
        for (int i = 0; i < n; i++) {
                cout << "Ingresa el entero " << i + 1 << ": ";
                cin >> nums2[i];
        }

        cout << "El número más grande del arreglo es: " << encontrarMayor(nums2, n - 1);

        cout << "\n\n---------- 4 ----------\n\n";

        cout << "Ingresa el tamaño del arreglo: ";
        cin >> n;

        int nums3[n];
        for (int i = 0; i < n; i++) {
                cout << "Ingresa el entero " << i + 1 << ": ";
                cin >> nums3[i];
        }


        return 0;
}