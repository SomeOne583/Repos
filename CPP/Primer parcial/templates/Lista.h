#include <vector>
using namespace std;

template<class B>
class Lista {
        public:
                Lista() {
                        size = 0;
                }

                bool agrega(B dato) {
                        int p = getPosicion(dato);
                        if (p == -1) {
                                listaDatos.push_back(dato);
                                size++;
                                return true;
                        } else
                                return false;
                }

                int getSize() {
                        return size;
                }

                B getElem(int i) {
                        if (i >= 0 && i < size)
                                return listaDatos[i];
                        else
                                throw out_of_range("Índice fuera de rango");
                }

                int getPosicion(B dato) {
                        int p = -1;
                        for (int i = 0; i < size; i++)
                                if (listaDatos[i] == dato)
                                        p = i;
                        return p;
                }
        private:
                int size;
                vector<B> listaDatos;
};