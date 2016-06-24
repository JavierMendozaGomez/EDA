/*GRUPO GISA02: Javier Mendoza Gomez y Daniel Martin Barrios*/
#include <iostream>
#include <vector>
using namespace std;
struct tInversion{
	long long int pos;
	long long int valor;
};
void mezcla(std::vector<tInversion> &v, const long long int &a, const long long int m, const long long int & b, long long int & res){
	
	tInversion *u = new tInversion[b - a + 1];
	int tam_i = m - a + 1; /// Tamaño de la primera mitad a mezclar
	long long int i, j, k;
	for (k = a; k <= b; k++)
		u[k - a] = v[k];
	i = 0;
	j = m - a + 1;
	k = a;
	while ((i <= m - a) && (j <= b - a)) {
		if (u[i].valor <= u[j].valor){
			v[k] = u[i];
			i = i + 1;
		}
		else {
		if (u[j].pos > u[i].pos){
			res += tam_i - i; //Le aumento  a res el numero de elementos que son mayores en la primera parte 
			}
			v[k] = u[j];
			j = j + 1;
		}
		k = k + 1;
	}

	while (i <= m - a) {
		v[k] = u[i];
		i = i + 1;
		k = k + 1;
	}
	while (j <= b - a) {
		v[k] = u[j];
		j = j + 1;
		k = k + 1;
	}
	delete[] u;
}
void calculaInversionesAux(std::vector<tInversion> &v, const long long int & a, const long long int & b, long long int & res){
	long long int  m;
	if (a<b){
		m = (a + b) / 2;
		calculaInversionesAux(v, a, m, res);
		calculaInversionesAux(v, m + 1, b, res);
		mezcla(v, a, m, b, res);
	}
}
long long int calculaInversiones(std::vector<tInversion> & v, const int & n){
	long long int a = 0, res = 0;
	calculaInversionesAux(v, a, n - 1, res);
	return res;
}
void resuelve(){
	long long int numElems;
	cin >> numElems;
	std::vector<tInversion> v(100000); /*Trate de crear un tInversion v[100000], pero como daba error utilize un std:vector*/
	tInversion inversion;
	for (int i = 0; i < numElems; i++){
		cin >> inversion.valor;
		inversion.pos = i;
		v[i] = inversion;
	}
		cout << calculaInversiones(v, numElems) << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}