// Clase Calificaciones

#include <string>
#include <iostream>
using namespace std;

class Calificacion {
        public:
                Calificacion();

                void setNombre(string);
                void setCalActividades(double);
                void setCalExamen(double);
                void setCalProyecto(double);

                string getNombreAlumno() { return nombreAlumno; };
                double getCalActividades() { return calActividades; };
                double getCalExamen() { return calExamen; };
                double getCalProyecto() { return calProyecto; };

                double final();

                void imprime();
        private:
                string nombreAlumno;
                double calActividades;
                double calExamen;
                double calProyecto;
};

Calificacion::Calificacion() {
        nombreAlumno = "";
        calActividades = 0;
        calExamen = 0;
        calProyecto = 0;
}

void Calificacion::setNombre(string nombre) {
        nombreAlumno = nombre;
}

void Calificacion::setCalActividades(double calificacion) {
        calActividades = calificacion;
}

void Calificacion::setCalExamen(double calificacion) {
        calExamen = calificacion;
}

void Calificacion::setCalProyecto(double calificacion) {
        calProyecto = calificacion;
}

double Calificacion::final() {
        return calExamen * .3 + calActividades * .3 + calProyecto * .4;
}

void Calificacion::imprime() {
        cout << "\n" << nombreAlumno << endl;
        cout << "Calificación del examen: " << calExamen << endl;
        cout << "Calificación de actividades: " << calActividades << endl;
        cout << "Calificación del proyecto: " << calProyecto << endl;
        cout << "Calificación final: " << final() << endl;
}