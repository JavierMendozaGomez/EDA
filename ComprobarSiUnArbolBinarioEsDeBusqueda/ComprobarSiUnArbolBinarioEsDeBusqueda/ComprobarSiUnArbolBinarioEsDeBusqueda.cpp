/*Nombre:JAVIER MENDOZA GOMEZ-ING SOFTWARE*/
#include<iostream>
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

template <class T>
void esBalanceado(const Arbin<T> &ar, bool &ok, T & minimo, T & maximo) {
	if (!ar.esVacio()) {
		if (ar.hijoDr().esVacio() && ar.hijoIz().esVacio()) {  //Si es hoja
			ok = ok && true;
			minimo = ar.raiz();
			maximo = ar.raiz();
		}
		else {
			T maxIz, minIz, maxDr, minDr;
			if (!ar.hijoIz().esVacio() && !ar.hijoDr().esVacio()) { // Si tiene ambos hijos
				esBalanceado(ar.hijoIz(), ok, minIz, maxIz);
				esBalanceado(ar.hijoDr(), ok, minDr, maxDr);
				ok = (maxIz < ar.raiz()) && (minDr > ar.raiz());
				minimo = std::min(minIz, min(minDr, ar.raiz()));
				maximo = std::max(maxIz, max(maxDr, ar.raiz()));
			}

			else if (!ar.hijoIz().esVacio()) { //Si solo tiene el hijo izdo
				esBalanceado(ar.hijoIz(), ok, minIz, maxIz);
				ok = (maxIz < ar.raiz());
				minimo = min(minIz, ar.raiz());
				maximo = max(maxIz, ar.raiz());
			}
			else {								//Si solo tiene el hijo derecho
				esBalanceado(ar.hijoDr(), ok, minDr, maxDr);
				ok = (minDr > ar.raiz());
				minimo = min(minDr, ar.raiz());
				maximo = max(maxDr, ar.raiz());
			}
		}
	}
}
bool resuelve() {
	int tipoArbol;
	cin >> tipoArbol;
	if (!cin)
		return false;
	if (tipoArbol == 1) {
		bool ok = true;
		char c ='.', minimo, maximo;
		Arbin<char> ar = leerArbol(c);
		esBalanceado(ar, ok, minimo, maximo);
		cout << minimo << " " << maximo;
		if (ok)
			cout << " SI" << endl;
		else
			cout << " NO" << endl;
		}
	else{
		bool ok = true;
		int num = -1, minimo, maximo;
		Arbin<int> ar = leerArbol(num);
		esBalanceado(ar, ok, minimo, maximo);
		cout << minimo << " " << maximo;
		if (ok)
			cout << " SI" << endl;
		else
			cout << " NO" << endl;
	}
	return true;
}
int main() {
	while (resuelve());
}