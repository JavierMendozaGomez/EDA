/*Javier Mendoza*/
#include <iostream>
#include "List.h"
using namespace std;
void mostrar(const List<int> &lista) {
	List<int>::ConstIterator it = lista.cbegin();
	List<int>::ConstIterator itFin = lista.cend();
	while (it != itFin) {
		cout << it.elem() << " ";
		it.next();
	}
	cout << endl;
}
bool resuelve() {
	int n, valor;
	cin >> n;
	if (n == -1)
		return false;
	List<int> lista;
	for (int i = 0; i < n; i++) {
		cin >> valor;
		lista.push_back(valor);
	}
	lista.intercalaListaV2();
	mostrar(lista);
	return true;
}
int main() {
	while (resuelve());
	return 0;
}