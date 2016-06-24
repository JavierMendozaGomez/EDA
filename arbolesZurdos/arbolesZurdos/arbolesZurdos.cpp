/*Nombre:Javier Mendoza Gomez GISA-51*/
/*Septiembre 2013 Parcial*/
#include<iostream>
#include <algorithm>
#include <climits>
#include "Arbin.h"
using namespace std;
struct solucion {
	bool ok;
	int altura;
};
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}



void esZurdo(const Arbin<int> & ar, solucion & sol) {
	if (ar.esVacio()) {
		sol.ok = true;
		sol.altura = 0;
	}
	else {
		solucion solIz, solDr;
		esZurdo(ar.hijoIz(), solIz);
		esZurdo(ar.hijoDr(), solDr);
		sol.ok = solIz.ok && solDr.ok && solIz.altura >= solDr.altura;
		sol.altura = 1 + std::min(solIz.altura, solDr.altura);
	}
}


void resuelve() {
	int fin = -1;
	solucion sol;
	Arbin<int> ar = leerArbol(fin);
	esZurdo(ar, sol);
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