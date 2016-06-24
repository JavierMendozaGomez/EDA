/*GRUPO: GISA23: Javier Mendoza Gómez y Daniel Martín Barrios*/
#include <iostream>
#include <algorithm>
using namespace std;
/*Coste logarítmico en el número de elementos del vector*/
int calculaMinimoAux(int v[],const int &a, const int &b){
	int longitud = b - a + 1;
	int m = (a+b) / 2;
	if (longitud == 1)
		return v[a];
	else{
		return std::min(calculaMinimoAux(v, a, m), calculaMinimoAux(v, m + 1, b));
	}
}
/*Coste logarítmico en el número de elementos*/
int calculaMinimo(int v[], const int  &n){
	int a = 0;
	return calculaMinimoAux(v,a, n - 1);
}
/*Coste lineal por la lectura de elementos*/
void resuelve(){
	int n;
	cin >> n;
	int v[90000];
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	cout << calculaMinimo(v, n) << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelve();
	}
	return 0;
}