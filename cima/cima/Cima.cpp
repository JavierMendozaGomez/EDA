/*GRUPO GISA23: Javier Mendoza Gómez y Daniel Martín Barrios*/
#include <iostream>
using namespace std;
/*Coste lineal en el número de elemento (version cutre falta mejorar el código)*/
void cima(int v[], const int &n, bool & existe, int &p){
	existe = false;
	if (n > 2){
		int i = 0; 
		while ((i != n - 2) && (v[i] < v[i+1]))
			i++;
		if (i != 0){
			p = i;
			int j = i;
			while ((j != n - 1) && (v[j] > v[j + 1]))
				j++;
			existe = (j == n - 1);
		}
	}
}

void resuelve(){
	int nElems ,p;
	bool existe;
	cin >> nElems;
	int v[10000];
	for (int i = 0; i<nElems; i++)
	{
		cin >> v[i];
	};
	cima(v, nElems, existe, p);
	if (existe)
		cout << "Si " << p << endl;
	else
		cout << "No" << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos;i++)
		resuelve();
	return 0;
}