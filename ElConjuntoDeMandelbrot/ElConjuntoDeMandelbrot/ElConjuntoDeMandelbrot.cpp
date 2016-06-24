#include "Complejo.h"
#include <iostream>
using namespace std;
Complejo<float> recursion(const Complejo<float> &c, const int &n,bool &encontrado){
	if (!encontrado){
		if (n == 0){
			return Complejo<float>(0,0);
		}
		else{
			Complejo<float> aux = recursion(c, n - 1, encontrado);
			Complejo<float> aux2 = (aux*aux) + c;
			encontrado = (aux2.modulo() > 2);
			return aux2;
		}
	}
	else
		return Complejo<float>();
}
void resuelve(){
	int numIteraciones;
	bool encontrado = false;
	float a, b;
	cin >> a >> b >> numIteraciones;
	Complejo<float> c(a, b);
	recursion(c, numIteraciones, encontrado);
	if (encontrado)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
			resuelve();
	return 0;
}