#include <iostream>
#include <string>
#include <fstream>
#include "Calificacion.h"
using namespace std;

int main() {
        string nombre;
        double c1, c2, c3;
        ifstream archEntrada;
        Calificacion lista[20];
        int contador = 0, opcion;

        archEntrada.open("calificaciones.txt");
        while (archEntrada >> nombre >> c1 >> c2 >> c3) {
                lista[contador].setNombre(nombre);
                lista[contador].setCalActividades(c1);
                lista[contador].setCalExamen(c2);
                lista[contador].setCalProyecto(c3);
                contador++;
        }
        archEntrada.close();

        cout << "Mi menu" << endl;
        do {
                cout << "\nOpcion 1: Listar a los alumnos" << endl;
                cout << "Opcion 2: Calificación mayor o igual a 85" << endl;
                cout << "Opcion 3: Salir" << endl;
                cin >> opcion;

                switch(opcion) {
                        case 1:
                                for (int i = 0; i < contador; i++)
                                        cout << lista[i].getNombreAlumno() << endl;
                                break;
                        case 2:
                                for (int i = 0; i < contador; i++)
                                        if (lista[i].final() >= 85)
                                                lista[i].imprime();
                                break;
                }
        } while (opcion != 3);

        return 0;
}