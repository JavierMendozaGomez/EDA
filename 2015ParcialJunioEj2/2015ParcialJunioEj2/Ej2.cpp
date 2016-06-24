#include <iostream>
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

int cuentaTiempo(const int & altura, const Arbin<char> &ar) {
	if (ar.esVacio())
		return 0;
	else {
		int tiempoIz, tiempoDr;
		tiempoIz = cuentaTiempo(altura + 1, ar.hijoIz());
		tiempoDr = cuentaTiempo(altura + 1, ar.hijoDr());
		if (ar.raiz() == 'X')
			return tiempoIz + tiempoDr + altura * 2;
		else
			return tiempoIz + tiempoDr;		
	}
}

void resuelve() {
	char fin = '.';
	Arbin<char> ar = leerArbol(fin);
	cout << cuentaTiempo(0, ar);
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}