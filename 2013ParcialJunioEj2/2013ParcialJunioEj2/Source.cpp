/*Nombre:Javier Mendoza Gomez GISA-51*/
/*Septiembre 2013 Parcial*/
#include<iostream>
#include <algorithm>
#include <climits>
#include <string>
#include "Arbin.h"
using namespace std;

struct solucion {
	int altura;
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
void esEquilibrado(const Arbin<int> & ar, solucion & sol) {
	if (ar.esVacio()) {
		sol.ok = true;
		sol.altura = 0;
	}
	else {
		solucion solIz, solDr;
		esEquilibrado(ar.hijoIz(), solIz);
		esEquilibrado(ar.hijoDr(), solDr);
		sol.ok = solDr.ok && solIz.ok && abs(solDr.altura - solIz.altura) <= 1;
		sol.altura = max(solIz.altura, solDr.altura) + 1;
	}
}

void resuelve() {
	int fin = -1;
	solucion sol;
	Arbin<int> ar = leerArbol(fin);
	esEquilibrado(ar, sol);
	if(sol.ok)
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