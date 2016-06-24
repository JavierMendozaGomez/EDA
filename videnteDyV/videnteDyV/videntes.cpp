#include <iostream>
using namespace std;
void buscaVidente(int v[], const int &a, const int &b, int & suma,bool &existe,int & p){
	if (b - a + 1 == 1){
		if (v[a] == suma){
			existe = true;
			p = a;
		}
		else{
			suma += v[a];
		}
	}
	else{
		int m = (a + b) / 2;
		buscaVidente(v, m + 1, b, suma,existe,p);  
		if (!existe)
			buscaVidente(v, a, m, suma,existe,p);
	}

}
void vidente(int v[], const int &n, bool & existe, int &p){
	existe = false;
	if ( n > 0){
		int a = 0;
		int suma = 0;
		buscaVidente(v, a, n - 1,suma,existe,p);
	}
}
void resuelve(){
	int n,p;
	bool existe;
	cin >> n;
	int v[100000];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vidente(v, n, existe, p);
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