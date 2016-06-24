#include <iostream>
using namespace std;
/*Coste lineal en el número de elementos del vector*/
long long int sumaBuenos(int v[], const int &n){
	int i = 0;
	long long int potencia = 1;
	long long int suma = 0;
	/*I= 0<=i<=N && suma = sumatorio de k :: 0<=k<i && bueno(k,v):v[k]  && potencia = 2^i*/
	while (i < n){
		if (v[i] == potencia){
			suma += v[i];
		}
		potencia = potencia * 2;
		i++;
	}
	return suma;
}
void resuelve(){
	int n;
	int v[20];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	cout << sumaBuenos(v, n) << endl;

}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelve();
	}
	return 0;
}