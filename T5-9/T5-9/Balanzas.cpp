#include <iostream>
using namespace std;
bool buscaMonedaFalsaAux(int v[], const int & a, const int &b){
	if (a - b == 1)
		return true;
	else{

	}
}
int buscaMonedaFalsa(int v[], const int & n){
	int a = 0;
	buscaMonedaFalsaAux(v, a, n - 1);
}
bool resuelve(){
	int n;
	cin >> n;
	if (n == -1)
		return false;
	int v[100];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	buscaMonedaFalsa(v, n);
	return true;
}
int main(){
	while (resuelve());
	return 0;
}