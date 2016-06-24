/*JAVIER MENDOZA GOMEZ- ING SOFTWARE*/
#include<iostream>
#include <exception>
#include <climits>
#include <algorithm>
#include "Arbin.h"
using namespace std;
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}
int buscaMinimoAux(const Arbin<int> & ar) {
	if (ar.esVacio())
		return INT_MAX;
	else {
		return min(buscaMinimoAux(ar.hijoIz()), min(buscaMinimoAux(ar.hijoDr()),ar.raiz()));
	}
}
int buscaMinimo(const Arbin<int> &ar){
	if (ar.esVacio())
			throw std::invalid_argument("Arbol vacio");
	return buscaMinimoAux(ar);
}
void resuelve() {
	int num = -1;
	try {
		cout << leerArbol(num).getAltura();
	}
	catch (...) {}
	cout << endl;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelve();
	}
	return 0;
}