#include <iostream>
using namespace std;
int calculaFobiFinal(int v[], int i, const int &n){
	if (i == n){
		return v[i - 1] + v[i - 2];
	}
	else{
		v[i] = v[i - 1] + v[i - 2];
		return calculaFobiFinal(v, i + 1, n);
	}
}
int calculaFobiAux(int v[], const int &n, const int &x, const int &y){
	if (v[n] != -1)
		return v[n];
	else
		v[n] = calculaFobiAux(v, n - 1, x, y) + calculaFobiAux(v, n - 2, x, y);
	return v[n];
}
int calculaFobi( const int &n, const int &x, const int &y){
	int v[100];
	v[0] = x;
	v[1] = y;
	for (int i = 2; i < 100; i++){
		v[i] = -1;
	}
	int i = 2;
	//return calculaFobiAux(v, n, x, y);
	return calculaFobiFinal(v, i, n);
}

bool resuelve(){
	int n, x, y;
	cin >> n;
	if (n == -1)
		return false;
	cin >> x >> y;
	cout << calculaFobi(n, x, y) << endl;
	return true;
}
int main(){
	while (resuelve());
	return 0;
}