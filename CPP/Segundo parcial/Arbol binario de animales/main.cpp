#include "BAT.h"
#include <iostream>
using namespace std;

int main() {
        BAT<string> bat;
        string continuar;
        do {
                cout << "\n------------------------------------\n";
                bat.play();
                cout << "Quieres seguir jugando: ";
                cin >> continuar;
        } while (continuar == "y");

        return 0;
}