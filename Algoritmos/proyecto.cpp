// Jose Humberto Cavazos - 531712
// Diego Mejía Montes - 569298
// Jan Carlo Reyes Martínez - 577441
// Proyecto final de Análisis y diseño de algoritmos
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

// Deminimos nuestro infinito como un número alto que sabemos es imposible salga como un camino posible, este se usa
// principalmente para las variables globales de menor
#define INF 1000000;

using namespace std;

// Definimos nuestras variables globales
// Empezamos por nuestra variable menor que será la que usemos para saber si hay algún resultado mejor
// acumBF se usa para calcular el costo acumulado de cierta solución en fuerza bruta
// acumGreedy guarda el acumulado de la solución que se va generando
int menor, acumBF, acumGreedy;

// Para el caso de fuerza bruta la solución esta en una string
string solucionBF;

// Esta es la máscara que se usa para programación dinámica, lo que representa son los nodos visitados
bitset<18> mDP(1);

// Estos vectores representan los caminos que se van construyendo para Branch and Bound y Greedy respectivamente
// En el de solucionBandB se guarda la solución que se encuentra en B&B si resulta tener un costo menor
vector<int> caminoBandB, solucionBandB, caminoGreedy;

// En estas matrices se guarda la matriz de adyacencias del grafo y la memorización de la programación dinámica
vector<vector<int>> grafo, cDP;

// Función para llenar el grafo
void llenarGrafo()
{
        // Se limpia el grafo
        grafo.clear();

        // Se llena el grafo de 99, esto es para que haya una conexión entre cualquier par de nodos como describe el problema
        grafo.resize(18, vector<int>(18, 99));
        
        // La diagonal de cada nodo con si mismo se pone en 0
        for (size_t i = 0; i < grafo.size(); i++)
                grafo[i][i] = 0;

        // Ya se ingresan individualmente las aristas
        grafo[0][1] = 3;
        grafo[0][2] = 7;
        grafo[0][14] = 1;
        grafo[1][0] = 3;
        grafo[1][2] = 4;
        grafo[2][0] = 7;
        grafo[2][1] = 4;
        grafo[2][3] = 4;
        grafo[2][6] = 4;
        grafo[3][2] = 4;
        grafo[3][10] = 2;
        grafo[4][5] = 8;
        grafo[4][7] = 3;
        grafo[4][8] = 3;
        grafo[5][4] = 8;
        grafo[5][6] = 7;
        grafo[5][8] = 8;
        grafo[6][2] = 4;
        grafo[6][5] = 7;
        grafo[6][9] = 2;
        grafo[6][10] = 7;
        grafo[7][4] = 3;
        grafo[7][8] = 4;
        grafo[7][11] = 3;
        grafo[7][14] = 7;
        grafo[8][4] = 3;
        grafo[8][5] = 8;
        grafo[8][7] = 4;
        grafo[8][9] = 3;
        grafo[8][11] = 8;
        grafo[8][12] = 6;
        grafo[9][6] = 2;
        grafo[9][8] = 3;
        grafo[9][10] = 9;
        grafo[9][13] = 3;
        grafo[10][3] = 2;
        grafo[10][6] = 7;
        grafo[10][9] = 9;
        grafo[10][13] = 4;
        grafo[11][7] = 3;
        grafo[11][8] = 8;
        grafo[11][14] = 7;
        grafo[11][15] = 5;
        grafo[12][8] = 6;
        grafo[12][13] = 4;
        grafo[13][9] = 3;
        grafo[13][10] = 4;
        grafo[13][12] = 4;
        grafo[13][17] = 9;
        grafo[14][0] = 1;
        grafo[14][7] = 7;
        grafo[14][11] = 7;
        grafo[14][15] = 7;
        grafo[15][11] = 5;
        grafo[15][14] = 7;
        grafo[15][16] = 5;
        grafo[15][17] = 2;
        grafo[16][15] = 5;
        grafo[16][17] = 4;
        grafo[17][13] = 9;
        grafo[17][15] = 2;
        grafo[17][16] = 4;
}

// Fuerza bruta
void BF(string str, int i, int n)
{
        // Caso base donde ya se llegó al último índice
        if (i == n - 1){
                // Se calcula el costo del camino actual
                acumBF=grafo[0][str[0]-65]+
                        grafo[str[0]-65][str[1]-65]+
                        grafo[str[1]-65][str[2]-65]+
                        grafo[str[2]-65][str[3]-65]+
                        grafo[str[3]-65][str[4]-65]+
                        grafo[str[4]-65][str[5]-65]+
                        grafo[str[5]-65][str[6]-65]+
                        grafo[str[6]-65][str[7]-65]+
                        grafo[str[7]-65][str[8]-65]+
                        grafo[str[8]-65][str[9]-65]+
                        grafo[str[9]-65][str[10]-65]+
                        grafo[str[10]-65][str[11]-65]+
                        grafo[str[11]-65][str[12]-65]+
                        grafo[str[12]-65][str[13]-65]+
                        grafo[str[13]-65][str[14]-65]+
                        grafo[str[14]-65][str[15]-65]+
                        grafo[str[15]-65][str[16]-65]+
                        grafo[str[16]-65][str[17]-65]+
                        grafo[str[17]-65][0];
                        
                // Se compara este costo con el mejor costo encontrado hasta ahora
                if(acumBF<menor){
                        // Si es mejor se actualiza el mejor costo
                        menor=acumBF;
                        // Se guarda la solución
                        solucionBF=str;
                }
                return;
        }
        
        // Se itera sobre todos los posibles indices
        for (int j = i; j < n; j++) {
                // Se intercambian nodos
                swap(str[i], str[j]);
                
                // Recursividad
                BF(str, i + 1, n);

                // Se regresa al estado original
                swap(str[i], str[j]);
        }
}

// Greedy
void Greedy(int acum)
{
        // Caso base, ya se completó el camino
        if (caminoGreedy.size() == grafo.size()) {
                // Se actualiza la variable global que guarda el acumulado de este camino
                // Para ello se debe agregar a mano el peso de regresar al principio
                acumGreedy = acum + grafo[caminoGreedy.back()][0];
                return;
        }

        // No es caso base
        // Definimos el nodo menor como -1 para indicar que aún no se calcula
        int nodoMenor = -1;

        // Definimos el nodo actual como el último que se agrego en el camino
        int nodoActual = caminoGreedy.back();

        // Iteramos en todos los posibles nodos
        for (int i = 0; i < grafo.size(); i++)
                // Revisamos que el nodo no sea parte del camino que ya va construido
                if (find(caminoGreedy.begin(), caminoGreedy.end(), i) == caminoGreedy.end())
                        // Revisamos que sea mejor opción que el nodoMenor que tenemos hasta el momento
                        // Si nodoMenor = -1 se reemplaza directamente porque significa que es el primero que analizamos
                        if (nodoMenor == -1 || grafo[nodoActual][i] < grafo[nodoActual][nodoMenor])
                                nodoMenor = i;

        // Se agrega al camino el nodoMenor que encontramos después de iterar por todos los posibles
        caminoGreedy.push_back(nodoMenor);

        // Se hace una sola llamada recursiva donde se aumenta el acumulado que lleva el camino
        Greedy(acum + grafo[nodoActual][nodoMenor]);
}

// Branch and Bound
void BandB(int acum)
{
        // Aquí sucede la poda, si mi acumulado actual es mayor a la mejor solución entonces no tiene caso seguir
        if (acum > menor)
                return;

        // Caso base donde ya todos los nodos estan en el camino generado
        if (caminoBandB.size() == grafo.size()) {
                // Al acumulado se le agrega el costo de volver al primer nodo
                acum += grafo[caminoBandB.back()][caminoBandB[0]];

                // Si este acumulado es mejor solución que la que tenía entonces se actualiza el mejor costo y la solución
                if (acum < menor) {
                        menor = acum;
                        solucionBandB = caminoBandB;
                }
                return;
        }

        // Se define el nodo actual como el último nodo en el camino generado
        int nodo = caminoBandB.back();

        // Se itera por todos los nodos
        for (int i = 0; i < grafo.size(); i++)
                // Se revisa que el nodo no este ya en el camino
                if (find(caminoBandB.begin(), caminoBandB.end(), i) == caminoBandB.end()) {
                        // Se agrega al camino
                        caminoBandB.push_back(i);

                        // Entra a la recursividad
                        BandB(acum + grafo[nodo][i]);

                        // Una vez que vuelve se quita el nodo para poder explorar más opciones
                        caminoBandB.pop_back();
                }

        // En este caso se uso un recorrido por profundidad pues no podemos podar hasta tener una solución,
        // por eso determinamos que usar un recorrido transversal no era la mejor opción
}

// Programación dinámica
int DP(int i, bitset<18> m)
{
        // Reviso si todos los bits de mi máscara son verdaderos osea que ya visite todos
        if (m.all())
                // Regreso el costo de ir desde mi posición actual al inicio
                return grafo[i][0];

        // Reviso si mi estado actual ya esta calculado
        if (cDP[i][m.to_ulong()] != -1)
                // Si ya lo calcule entonces regreso lo que tengo guardado
                return cDP[i][m.to_ulong()];
        
        // Defino un menor local para comparar la solución obtima para el subproblema actual
        int menorLocal = INF;

        // Itero sobre los nodos
        for (int k = 0; k < grafo.size(); k++) {
                // Reviso si el nodo esta visitado
                if (!m[k]) {
                        // Lo marco como visitado
                        m[k] = 1;

                        // Calculo el subproblema que surje a partir de ese nodo y reviso si es mejor solución que la que tenía
                        menorLocal = min(menorLocal, grafo[i][k] + DP(k, m));

                        // Lo marco como no visitado para seguir explorando
                        m[k] = 0;
                }

                // Guardo lo que calcule para ahorrar tiempo después
                cDP[i][m.to_ulong()] = menorLocal;
        }
        return cDP[i][m.to_ulong()];
}

// Función principal y donde esta el menú
int main()
{
        // Lleno el grafo
        llenarGrafo();

        // En esta variable se guarda la elección del usuario
        string eleccion;
        
        // Ciclo para que el programa siga mientras el usuario quiera
        do {
                // Imprimo el menú
                cout << "Menú\n";
                cout << "1. Fuerza bruta\n";
                cout << "2. Greedy\n";
                cout << "3. Ramificación y poda\n";
                cout << "4. Programación dinámica\n";
                cout << "5. Salir\n";
                cout << ">>> ";

                // Valido la entrada
                while (cin >> eleccion && !(eleccion == "1" || eleccion == "2" || eleccion == "3" || eleccion == "4" || eleccion == "5"))
                        cout << "Ingresa un valor válido\n>>> ";

                if (eleccion == "1") {
                        // Le imprimo un mensaje cómico
                        cout << "Prepara una silla porque estarás aquí un buen rato\n";

                        // Asigno mi valor menor por si algún método la uso antes
                        menor = INF;

                        // También reinicio mi variable de solución
                        solucionBF = "";

                        // Ejecuto mi método
                        BF("ABCDEFGHIJKLMNOPQR", 0, 18);

                        // Hago la impresión de resultados
                        cout << "Camino: ";
                        for (size_t i = 0; i < solucionBF.size(); i++)
                                cout << (solucionBF[i] - 65) << " -> ";
                        cout << (solucionBF[0] - 65) << "\nCosto del recorrido: " << menor << "\n";
                } else if (eleccion == "2") {
                        // Limpio mi camino y le agrego el 0 porque de ahí empiezo
                        caminoGreedy.clear();
                        caminoGreedy.push_back(0);

                        // Llamo a la función
                        Greedy(0);

                        // Imprimo resultados
                        cout << "Camino: ";
                        for (size_t i = 0; i < caminoGreedy.size(); i++)
                                cout << caminoGreedy[i] << " -> ";
                        cout << caminoGreedy[0] << "\nCosto del recorrido: " << acumGreedy << "\n";
                } else if (eleccion == "3") {
                        // Reinicio mi variable global de menor
                        menor = INF;

                        // Limpio mi camino y le agrego el 0 porque de ahí empieza
                        caminoBandB.clear();
                        caminoBandB.push_back(0);

                        // Limpio la solución que tenía
                        solucionBandB.clear();

                        // Llamo la función
                        BandB(0);

                        // Imprimo resultados
                        cout << "Camino: ";
                        for (size_t i = 0; i < solucionBandB.size(); i++)
                                cout << solucionBandB[i] << " -> ";
                        cout << solucionBandB[0] << "\nCosto del recorrido: " << menor << "\n";
                } else if (eleccion == "4") {
                        // Limpio mi memorización
                        cDP.clear();

                        // La lleno de -1 porque eso indica que no se ha calculado
                        cDP.resize(18, vector<int>(pow(2, 18) - 1, -1));

                        // Imprimo el resultado llamando directamente a la función
                        cout << "Costo: " << DP(0, mDP) << "\n";
                }
        } while (eleccion != "5");
        
        return 0;
}
