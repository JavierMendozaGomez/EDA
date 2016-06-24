#include <iostream>
#include <string>
#include "Libreria.h"

// Muestra el contenido de una lista
template <class T>
void mostrar(list<T> const& l) {
	typename list<T>::const_iterator it = l.cbegin();
	typename list<T>::const_iterator itFin = l.cend();
	while (it != itFin) {
		cout << *it << '\n';
		++it;
	}

}

bool resolverCaso() {
	Libreria c;
	string tituloLibro;
	int numUnidades;
	string nombreOp;
	int numOp;
	cin >> numOp;
	if (!cin) return false;
	for (int i = 0; i < numOp; ++i) {
		cin >> nombreOp;
		char aux;
		cin.get(aux); // lee el blanco despues del nombre de la operacion
		if (nombreOp == "nuevoLibro") {
			cin >> numUnidades;
			char aux;
			cin.get(aux); // lectura del blanco entre las unidades y el titulo
			//cin.ignore();
			getline(cin, tituloLibro);
			c.nuevoLibro(tituloLibro, numUnidades);
		}
		else if (nombreOp == "comprar") {
			getline(cin, tituloLibro);
			try {
				c.comprar(tituloLibro);
			}
			catch (out_of_range const& e) {  // No hay ejemplares
				cout << e.what() << '\n';
				cout << "---\n";
			}
			catch (invalid_argument const& e) {  //Libro no existente
				cout << e.what() << '\n';
				cout << "---\n";
			}
		}
		else if (nombreOp == "muestraTodos")
			c.muestraTodos();
		else if (nombreOp == "estaLibro") {
			getline(cin, tituloLibro);
			if (c.estaLibro(tituloLibro)) {
				cout << "El libro " << tituloLibro;
				cout << " esta en el sistema\n";
			}
			else {
				cout << "No existe el libro " << tituloLibro;
				cout << " en el sistema\n";
			}
			cout << "---\n";
		}
		else if (nombreOp == "elimLibro") {
			getline(cin, tituloLibro);
			c.elimLibro(tituloLibro);
		}
		else if (nombreOp == "numEjemplares") {
			getline(cin, tituloLibro);
			if (c.estaLibro(tituloLibro)) {
				cout << "Existen " << c.numEjemplares(tituloLibro);
				cout << " ejemplares del libro " << tituloLibro << '\n';
			}
			else {
				cout << "No existe el libro " << tituloLibro;
				cout << " en el sistema\n";
			}
			cout << "---\n";
		}
		else if (nombreOp == "top10") {
			mostrar(c.top10());
			cout << "---\n";
		}
	}
	cout << "------" << endl;
	return true;

}
int main() {
	while (resolverCaso());
	return 0;
}
