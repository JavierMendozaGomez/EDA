/*GRUPO GISA23: Javier Mendoza Gomez y Daniel Martin Barrios*/
#include <iostream>
using namespace std;
/*INV=0<=i<=n:(res=(sumatorio j: 0<=j<=i:x^i)) && potencia = x^i)) && 1<=x<=100 && n<=1*10^6*/

/*
Descripcion:Funcion que dado un exponente y una base devuelve su sumatorio
Coste lineal en el valor del exponente pasado por parámetro
*/
int calculaSumatorioPotencia(int x, int n) {
	int i = 0;
	int res = 1;
	int potencia = 1;
	while (i < n){
		potencia = potencia*x;
		potencia = potencia%1000007;
		res = res+potencia;
		res = res % 1000007;
		i++;
	}
	return res ;
}
/*Funcion que imprime el resultado de calculaSumatorio
Orden lineal por coste la función calculaSumatorio*/
bool resuelve() {

	int x, n;
	cin >> x >> n;

	if (!cin)
		return false;
	cout << calculaSumatorioPotencia(x, n) << endl;
	return true;
}

int main() {

	// Resolvemos
	while (resuelve()) {}
}