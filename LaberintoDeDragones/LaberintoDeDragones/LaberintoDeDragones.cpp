/*Nombre: Javier Mendoza Gomez GIS-A51*/
#include "Arbin.h"
#include <iostream>
#include <string>
#include <climits>
using namespace std;
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}

template <class T>
void encuentraCaminov2(const Arbin<T> &ar, const T &dragon, T &puerta, int &longActual, int &longMejor) {
	if (ar.esVacio()) {
		return;
	}
	else {
		if (ar.raiz() == dragon)
			longActual++;
		if (ar.hijoIz().esVacio() && ar.hijoDr().esVacio()) { // Si es hoja
			if (longActual < longMejor) {
				puerta = ar.raiz();
				longMejor = longActual;
			}
		}
		else {
			encuentraCamino(ar.hijoIz(), dragon, puerta, longActual, longMejor);
			encuentraCamino(ar.hijoDr(), dragon, puerta, longActual, longMejor);
		}
		if (ar.raiz() == dragon)
			longActual--;
	}
}

template <class T>
void encuentraCamino(const Arbin<T> &ar,const T &dragon, T &puerta, int &longActual, int &longMejor) {
	if (ar.esVacio()) {
		return;
	}
	else {
		if (ar.raiz() == dragon)
			longActual++;
		if (ar.hijoIz().esVacio() && ar.hijoDr().esVacio()) { // Si es hoja
			if (longActual < longMejor) {
				puerta = ar.raiz();
				longMejor = longActual;
			}
		}

		else if (!ar.hijoIz().esVacio() && !ar.hijoDr().esVacio()) { // Si tiene ambos hijos
			encuentraCamino(ar.hijoIz(), dragon, puerta, longActual, longMejor);
			encuentraCamino(ar.hijoDr(), dragon, puerta, longActual, longMejor);
		}
		else if (!ar.hijoIz().esVacio()) {		//Si solo tiene hijo Izquierdo
			encuentraCamino(ar.hijoIz(), dragon, puerta, longActual, longMejor);
		}
		else {							//Si solo tiene hijo derecho
			encuentraCamino(ar.hijoDr(), dragon, puerta, longActual, longMejor);
		}

		if (ar.raiz() == dragon)
			longActual--;
		}
}

void resuelve() {
	string fin = "...";
	string dragon = "Dragon";
	string puerta;
	int longActual = 0, longMejor = INT_MAX;
	Arbin<string> ar = leerArbol(fin);
	encuentraCamino(ar, dragon, puerta, longActual, longMejor);
	cout << puerta << " " << longMejor << endl ;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelve();
	}
	return 0;
}