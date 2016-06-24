/*Nombre:Javier Mendoza Gomez GISA-51*/
#include<iostream>
#include <algorithm>
#include <climits>
#include "Arbin.h"
using namespace std;
struct solucion {
	int numEquipos;
	int numExRuta;
};
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}



void rescate(const Arbin<int> & ar, solucion & sol) {
	if (ar.esVacio()) {
		sol.numEquipos = 0;
		sol.numExRuta = 0;
	}
	else {
			solucion solIz, solDr;
			rescate(ar.hijoIz(), solIz);
			rescate(ar.hijoDr(), solDr);
			sol.numEquipos = solIz.numEquipos + solDr.numEquipos;
			if (sol.numEquipos == 0 && ar.raiz() != 0) {
				sol.numEquipos++;
			}
			sol.numExRuta = std::max(solIz.numExRuta, solDr.numExRuta) + ar.raiz();
		}
	}


void resuelve() {
	int fin = -1;
	int numExcursionistasActual;
	solucion sol;
	Arbin<int> ar = leerArbol(fin);
	rescate(ar, sol);
	cout << sol.numEquipos << " " << sol.numExRuta << endl;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}