 /*Nombre:Javier Mendoza Gomez GISA-51*/
#include<iostream>
#include <algorithm>
#include <climits>
#include "Arbin.h"
using namespace std;
struct solucion {
	bool ok;
	int sumaNodos;
	int numNodos;
};
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}



void arbolesValiosos(const Arbin<int> & ar, solucion & sol) {
	if (ar.esVacio()) {
		sol.ok = true;
		sol.numNodos = 0;
		sol.sumaNodos = 0;
	}
	else {
		solucion solIz, solDr;
		arbolesValiosos(ar.hijoIz(), solIz);
		arbolesValiosos(ar.hijoDr(), solDr);
		sol.numNodos = solIz.numNodos + solDr.numNodos + 1 ;
		sol.sumaNodos = solIz.sumaNodos + solDr.sumaNodos + ar.raiz();
		sol.ok = solIz.ok && solDr.ok && (sol.sumaNodos >= sol.numNodos);
	}
}


void resuelve() {
	int fin = -1;
	int numExcursionistasActual;
	solucion sol;
	Arbin<int> ar = leerArbol(fin);
	arbolesValiosos(ar, sol);
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