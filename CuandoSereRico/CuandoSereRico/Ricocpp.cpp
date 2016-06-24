/*GRUPO GISA23:Javier Mendoza Gómez y Daniel Martín Barrios*/
#include <iostream>
using namespace std;
/*Coste Lineal en el numero de dias?*/
int calculaDias(long long int &numCent){
	int numDias;
	if (numCent == 0){
		numDias = 0;
	}
	else if (numCent == 1){
		numDias = 1;
	}
	else if (numCent == 2){
		numDias = 2;
	}
	else{
	    numDias = 2;
		int dia1 = 1, dia2 = 1,aux;
		long long int suma = 2 * dia1 + dia2;
		while (suma <= numCent){
			suma += 2 * dia1 + dia2;
			aux = dia1;
			dia1 = dia2;
			dia2 = 2 * aux + dia2;
			numDias++;
		}
	}
	return numDias;
}
void resuelve(){
	long long int numCent;
	cin >> numCent;
	cout << calculaDias(numCent) << endl;
	}

int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}