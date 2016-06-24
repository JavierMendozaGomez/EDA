//============================================================================
// Name        : Pares.cpp
// Author      : Clara Segura
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

#include <iostream>
using namespace std;

int pares(int v[], int n)
{
	int contador = 0;
	for (int i = 0; i < n; i++){
		if (v[i] % 2 == 0)
			contador++;
	}
	return contador;
}


void resuelve()
{
	int nElems;
	cin >> nElems;
	int v[10000];
	for (int i = 0; i<nElems; i++)
	{
		cin >> v[i];
	};
	cout << pares(v, nElems) << endl;



}

int main() {
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i<nCasos; i++) {
		resuelve();
	}

	return 0;
}