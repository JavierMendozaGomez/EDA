#include <iostream>
using namespace std;
int buscaPrimerImpar(int v[], const int &a, const int &b){
	if (b - a + 1 < 1)
		return 0;		//Si no hay elementos, entonces el primer impar es 0
	else if (b - a + 1 == 1){
		if (v[a]%2 == 0)
			return 999;
		return a;
	}
	else{
		int m = (a + b) / 2;
		int aux = buscaPrimerImpar(v, a, m);
		if (aux == 999)
			return buscaPrimerImpar(v, m + 1, b);
		return aux;
	}
}
bool todosImpares(int v[], const int &a, const int &b){
	if (b - a + 1 < 1)  // Si el intervalo es vacío, entonces todos son Impares(para todo e intervalo vacio devuelve true)
		return true;
	else if (b - a + 1 == 1)
		return (v[a]%2 == 1);
	else{
		int m = (a + b) / 2;
		return todosImpares(v, a, m) && todosImpares(v, m + 1, b);
	}
}
void paresImpares(int v[], const int &n, bool & existe, int &p){
	int a = 0;
	p = buscaPrimerImpar(v, a, n - 1);
	if (p == 999)		//Si no existen impares, entonces existe la posicion p
		p = n;
	existe = todosImpares(v, p, n - 1);
}
void resuelve(){
	int v[10000];
	bool existe;
	int n,p;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	paresImpares(v, n, existe, p);
	if (existe)
		cout << "Si " << p << endl;
	else
		cout << "No" << endl;
 }
int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}