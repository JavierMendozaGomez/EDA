//Javier Mendoza Gomez
#include "TreeMap.h"
#include <iostream>
using namespace std;
int buscaX(const TreeMap<int, float> &f, float y) {
	try {
		return f.atValor(y);
	}
	catch (const out_of_range &e) {
		return -1;
	}
}
bool resuelve() {
	int n,clave;
	float valor;
	cin >> n;
	if (n == 0)
		return false;
	TreeMap<int, float> mapa;
	for (int i = 0; i < n; i++) {
		cin >> clave >> valor;
		mapa.insert(clave, valor);
	}
	cout << "Valor a buscar: ";
	cin >> valor;
	cout << buscaX(mapa,valor) << endl;
}
int main() {
	while (resuelve());
	return 0;
}