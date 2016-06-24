/*Nombre:Javier Mendoza Gomez GISA-51*/
/*Septiembre 2013 Parcial*/
#include<iostream>
#include <algorithm>
#include <climits>
#include <string>
#include "Arbin.h"
using namespace std;
bool esPrincesa(int num) {
	return num != 0 && num %2 == 0;
}
struct solucion {
	int alturaMejor;
	int princesa;
};
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}

int cuentaPrincesas(const Arbin<int> &ar) {
	if (ar.esVacio() || ar.raiz() == 1)
		return 0;
	else {
		int princesasDr, princesasIz;
		princesasIz = cuentaPrincesas(ar.hijoIz());
		princesasDr = cuentaPrincesas(ar.hijoDr());
		if (esPrincesa(ar.raiz()))
			return princesasIz + princesasDr + 1;
		else
			return princesasIz + princesasDr;
	}
}

void princesaCercana(const Arbin<int> &ar, const int &altura, solucion &sol) {
	if (ar.esVacio() || ar.raiz() == 1)
		return;
	else {
		if (esPrincesa(ar.raiz())) {
			if (altura < sol.alturaMejor) {
				sol.alturaMejor = altura;
				sol.princesa = ar.raiz();
			}
		}
		else {
			princesaCercana(ar.hijoIz(), altura + 1, sol);			
			princesaCercana(ar.hijoDr(), altura + 1, sol);
		}
	}
}

void resuelve() {
	int fin = -1;
	solucion sol;
	sol.alturaMejor = INT_MAX;
	Arbin<int> ar = leerArbol(fin);
	cout << "El numero de princesas es " <<  cuentaPrincesas(ar) << endl;
	princesaCercana(ar, 0, sol);
	cout << "La princesa mas cercana es "  << sol.princesa << endl;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}