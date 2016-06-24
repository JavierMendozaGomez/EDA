//Javier Mendoza Gomez-GISA51
#include<iostream>
#include <fstream>
#include "SinglyLinkedList.h"
using namespace std;
bool resuelve() {
	int n,valor;
	cin >> n;
	if(!cin)
		return false;
	SinglyLinkedList<int> lista;
	for (int i = 0; i < n; i++) {
		cin >> valor;
		lista.push_front(valor);
	}
	lista.imprime();
	lista.invierte();
	return true;
}
int main() {
	while (resuelve());
	return 0;
}