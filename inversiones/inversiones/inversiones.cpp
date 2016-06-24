#include <iostream>
using namespace std;
struct tInversion{
	long long int pos;
	long long int valor;
};
void mezcla(tInversion v[], const long long int &a, const long long int m, const long long int & b, long long int & res){

	tInversion *u = new tInversion[b - a + 1];
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
void calculaInversionesAux(tInversion v[],const long long int & a, const long long int & b,long long int & res){
	long long int  m;
	if (a<b){
		m = (a + b) / 2;
		calculaInversionesAux(v, a, m,res);
		calculaInversionesAux(v, m + 1, b,res);
		mezcla(v, a, m, b,res);
	}
} 
long long int calculaInversiones(tInversion v[], const int & n){
	long long int a = 0, res = 0;
    calculaInversionesAux(v, a, n - 1, res);
    return res;
}
void resuelve(){
	long long int numElems, res = 0,a = 0;
	cin >> numElems;
	tInversion v[100000];
	tInversion inversion;
	for (int i = 0; i < numElems; i++){
		cin >> inversion.valor;
		inversion.pos = i;
		v[i] = inversion;
	}
	cout << "indio jose" << endl;
	cout << calculaInversiones(v,numElems) << endl;
	cout << "sisi" << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}