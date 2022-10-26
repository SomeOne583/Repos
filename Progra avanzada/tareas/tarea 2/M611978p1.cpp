// Problema Combination
// Jan Carlo Reyes Martínez, 577441
// Juan Manuel Cuevas Gaytan, 611978
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica

#include <iostream>

int main() {
        // Iniciamos nuestras variables para leer los datos del candado y en giro es el contador
        int inicial, d1, d2, d3, giro;

        // Lectura inicial
        std::cin >> inicial >> d1 >> d2 >> d3;
        do {
                // El primer paso es dar dos giros completos, osea 720 grados
                giro = 720;

                // Si el inicial es menor que el primer digito sumamos 40 porque tenemos que pasar por el cero
                inicial = (inicial < d1) ? inicial + 40 : inicial;
                // Agregamos la diferencia entre el inicial y el primer digito
                giro += ((360 * (inicial - d1)) / 40);

                // Luego hay que dar un giro completo
                giro += 360;

                // Aquí es el mismo razonamiento que con inicial pero como después volvemos a usar d2 no se reasigna
                if (d2 < d1) {
                        giro += ((360 * (d2 + 40 - d1)) / 40);
                } else {
                        giro += ((360 * (d2 - d1)) / 40);
                }
                if (d2 < d3) {
                        giro += ((360 * (d2 + 40 - d3)) / 40);
                } else {
                        giro += ((360 * (d2 - d3)) / 40);
                }

                std::cout << giro << std::endl;

                std::cin >> inicial >> d1 >> d2 >> d3;
        } while (inicial != 0 || d1 != 0 || d2 != 0 || d3 != 0);

        return 0;
}