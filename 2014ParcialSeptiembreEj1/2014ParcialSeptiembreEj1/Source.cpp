/*Nombre:Javier Mendoza Gomez GISA-51*/
/*Septiembre 2013 Parcial*/
#include<iostream>
#include <algorithm>
#include <climits>
#include <string>
#include "Arbin.h"
using namespace std;

struct solucion {
	int edad;
	bool ok;
};
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}
void esGenealogico(const Arbin<int> & ar, solucion & sol) {
	if (ar.esVacio()) {
		sol.ok = true;
	}
	else {
		solucion solIz, solDr;
		sol.edad = ar.raiz();
		if (ar.hijoDr().esVacio() && ar.hijoIz().esVacio())  //Si es hoja
			sol.ok = true;
		else if (!ar.hijoIz().esVacio() && ar.hijoDr().esVacio()) { //Si solo tiene un hijo
			solucion solIz;
			esGenealogico(ar.hijoIz(), solIz);
			sol.ok = solIz.ok && (sol.edad - 18 >= solIz.edad);
		}
		else {
			solucion solIz, solDr;
			esGenealogico(ar.hijoIz(), solIz);
			esGenealogico(ar.hijoDr(), solDr);
			sol.ok = solIz.ok && (sol.edad - 18 >= solIz.edad) && (sol.edad - 18 >= solDr.edad) && (solIz.edad - 2 >= solDr.edad);
		}
	}
}

void resuelve() {
	int fin = -1;
	solucion sol;
	Arbin<int> ar = leerArbol(fin);
	esGenealogico(ar, sol);
	if (sol.ok)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}