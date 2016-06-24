/*Grupo GISA23: Javier Mendoza Gomez y Daniel Martin Barrios*/
#include <iostream>
using namespace std;
/*Coste logaritmico en el número de elementos del vector*/
void buscaMayor(int v[], const int &a, const int &b,bool &existe,int &p){
	if (b - a  + 1 == 1){
		if (v[a] < v[a + 1]){
			existe = false;
		}
		else{
			existe = true;
			p = a;
		}
	}
	else{
		int m = (a + b) / 2;
		 buscaMayor(v, a, m,existe,p);
		if (!existe)
			 buscaMayor(v, m + 1, b,existe,p);	
	}
}
/*Coste logaritmico en el número de elementos del vector*/
bool todosMenores(int v[], const int &a, const int &b){
	if (b - a + 1 == 1)						// el intervalo no puede ser vacío,asi que no considero ese caso
		return (v[a] > v[a + 1]);
	else{
		int m = (a + b) / 2;
		return todosMenores(v, a, m) && todosMenores(v, m + 1, b);
	}
}
/*Coste logaritmico en el numero de elementos del cextor*/
void cima(int v[], int n, bool &existe, int &p){
	if (n < 3){
		existe = false;
	}
	else{
		int a = 0;
		buscaMayor(v,a,n-2,existe,p);
		if (p == 0)
			existe = false;
		if (existe){				//Esta ordenado crecientemente y no existe ningun elemento que sea menor que su anterior, o existe y está en la primera posicion
			existe = todosMenores(v, p, n - 2);
		}
	
	}
}
/*Coste lineal por la lectura de datos*/
void resuelve(){
	int n,p;
	bool existe;
	int v[10000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cima(v, n, existe, p);
	if (existe)
		cout << "Si " << p << endl;
	else
		cout << "No" << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}