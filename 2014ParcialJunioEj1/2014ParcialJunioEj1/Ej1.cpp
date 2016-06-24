/*Javier Mendoza*/
#include <iostream>
#include "List.h"
using namespace std;
void mostrar(List<int> lista) {
	List<int>::ConstIterator it = lista.cbegin();
	List<int>::ConstIterator itFin = lista.cend();
	while (it != itFin) {
		cout << it.elem() << " ";
		it.next();
	}
	cout << endl;
}
bool resuelve() {
	int n,valor,pos;
	cin >> n;
	if (n == -1)
		return false;
	List <int> lista;
	for (int i = 0; i < n; i++) {
		cin >> valor;
		lista.push_back(valor);
	}
	cout << "Valor a insertar :";
	cin >> valor;
	cout << "Posicion en la que se inserta:";
	cin >> pos;
	lista.insertaNodo(valor, pos);
	mostrar(lista);
}
int main() {
	while (resuelve());
	return 0;
}