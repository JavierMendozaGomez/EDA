/*Nombre:Javier Mendoza Gomez GISA-51*/
#include<iostream>
#include "List.h"
#include <algorithm>
#include <climits>
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
bool coinciden(const Arbin<T> & ar, const List<T> &pre) {
	int numNodos = 0;
	List<T>::ConstIterator it = pre.cbegin();
	List<T>::ConstIterator itFin = pre.cend();
	return (sonIguales(ar, it, itFin, numNodos) && numNodos == pre.size());
}

template<class T>
bool sonIguales(const Arbin<T> &ar,  List<int>::ConstIterator &it,  List<int>::ConstIterator &itFin, int &numNodos) {
	if (ar.esVacio())
		return true;
	else {
		if (it != itFin && it.elem() == ar.raiz()) {
			numNodos++;
			it.next();
			return sonIguales(ar.hijoIz(), it, itFin, numNodos) && sonIguales(ar.hijoDr(), it, itFin,numNodos);
		}
		else
			return false;
	}
}
void resuelve() {
	int fin = -1,num;
	cout << "Arbol: ";
	int numExcursionistasActual;
	Arbin<int> ar = leerArbol(fin);
	cout << "Lista: ";
	List<int> pre;
	cin >> num;
	while (num != -1) {
		pre.push_back(num);
		cin >> num;
	}
	if(coinciden(ar, pre))
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