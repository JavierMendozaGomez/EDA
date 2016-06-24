#include <iostream>
using namespace std;
void calculaElementosAux(int v[], int a, int b, bool & ordenados, int &pos){
	if (a == b){
		if (v[a - 1] > v[a])
			ordenados = true;
		else
		{
			ordenados = false;
			pos = a;

		}
	}
	else{
		int m = (a + b) / 2;
		calculaElementosAux(v, m + 1, b, ordenados, pos);
		if (ordenados)
			calculaElementosAux(v, a, m, ordenados, pos);
	}
}
void calculaElementos(int v[], int n,bool &ordenados, int &pos){
	if (n == 1)
		ordenados = true;
	else{
		int a = 1;
		calculaElementosAux(v, a, n - 1, ordenados, pos);
	}
}
bool resuelve(){
	int n;
	cin >> n;
	if (n == -1)
		return false;
	int v[100];
	bool ordenados;
	int pos;
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	calculaElementos(v, n,ordenados,pos);
	if (ordenados)
		cout << "0" << endl;
	else{
		cout << n - pos;
	}
	return true;
}
int main(){
	while (resuelve());
	return 0;
}