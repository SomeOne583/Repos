/*

21 de enero de 2022
Ramiro Castellanos Barron 606938
Joel Lopez Plata 570221
Jan Carlo Reyes 577441
Damos nuestra palabra de que hemos realizado esta actividad con integridad academica.

*/

#include "iostream"
#include "string"
using namespace std;

//1. Imprime la suma de los números de un entero proporcionado por el usuario.
int suma(int n)
{
	if(n == 1)
		return n;
	else
		return suma(n - 1) + n;
}

//2. Escribe una función recursiva que invierta una cadena (string).
string inversion(string s)
{
	int tamanio = s.size();
	if(tamanio == 1)
		return s;
	else
		return s[tamanio - 1] + inversion(s.substr(0, tamanio - 1));
}

//3. Escribe una función recursiva que determine cuando una cadena es o no es un palíndromo. (Un palíndromo es una cadena que se lee (o se escribe) igual de izquierda a derecha que de derecha a izquierda).
bool palindromo(string s)
{
	int tamanio = s.size();
	
	if(tamanio <= 1)
		return true;
	else
	{
		bool val = s[0] == s[tamanio-1];
		return val * palindromo(s.substr(1, tamanio - 2));
	}
}

//4. Imprimir el siguiente patrón con el uso de recursividad, pregunta al usuario el número de renglones.
void imprimirRenglones(int cant, int _cant)
{
	if(cant == 1)
		cout << string(_cant - cant, ' ') << char('*');
	else {
		imprimirRenglones(cant - 1, _cant);
		cout << endl << string (_cant - cant, ' ') << string(2 * cant - 1, '*');
	}
}

void imprimirMenu()
{
	cout << "\n1. Suma numeros enteros.\n2. Invertir cadena.\n3. Revision palindromo.\n4. Imprimir piramide.\n5. Salir.\n\n\t>>\tIngrese una opcion: ";
}

int main()
{
	cout << endl << suma(5);
	cout << endl << inversion("Ramiro");
	cout << endl << palindromo("RamiroorimaR") << endl << endl;
	imprimirRenglones(7, 7);
	string string1, string2;
	int o;
	do
	{
		imprimirMenu();
		cin >> o;
		switch(o)
		{
			case 1: 
				int num;
				cout << "Ingrese un numero entero: ";
				cin >> num;
				cout << "La suma de tu numero es: " << suma(num);
				break;
			case 2: 
				cout << "Ingrese un string a invertir: ";
				cin >> string1;
				cout << "La inversion de " << string1 << " es: " << inversion(string1);
				break;
			case 3:
				cout << "Ingrese la palabra que desea validar: ";
				cin >> string2;
				if(palindromo(string2))
					cout << string2 << " si es un palindromo.";
				else
					cout << string2 << " no es un palindromo.";
				break;
			case 4:
				int niveles;
				cout << "Ingrese la cantidad de niveles de su piramide: ";
				cin >> niveles;
				imprimirRenglones(niveles, niveles);
				break;
			default:
				break;
		}
	} while(o != 5);
	return 0;
}