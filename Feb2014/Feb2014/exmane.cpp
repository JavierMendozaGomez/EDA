#include <iostream>
#include <cmath>
using namespace std;
bool esCaucasicoAux2(int v[], int a, int b, int &res){
	int paresDr;
	int paresIz;
	if (a == b){
			if (v[a] % 2 == 0)
				res = 1;
			else{
				res = 0;
			}
			return true;
		}

	else{
			int m = (a + b) / 2;
			esCaucasicoAux2(v, a, m, paresDr);
			esCaucasicoAux2(v, m + 1, b, paresIz);
			res = paresDr + paresIz;
			return  (abs(paresDr - paresIz) <= 2);
		}
	
}
void esCaucasicoAux(int v[], int a, int b,bool &cau,int &res){
	if (cau){
		if (b - a + 1 == 1){
			if (v[a] % 2 == 0)
				res += 1;
		}
		else{
			int m = (a + b) / 2;
			int paresDr = 0;
			esCaucasicoAux(v, a, m, cau, paresDr);
			int paresIz = 0;
			esCaucasicoAux(v, m+1, b, cau, paresIz);
			cau = (abs(paresDr - paresIz) <= 2);
			res = paresDr + paresIz;
		}
	}
}
bool esCaucasico(int v[], int n){/**/
	int a = 0;
	int res;
	return esCaucasicoAux2(v,a,n-1,res);
}
bool resuelve(){
	int n;
	cin >> n;
	if (n == -1)
		return false;
	int v[100];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	if (esCaucasico(v, n))
		cout << "Si" << endl;
	else
		cout << "No" << endl;
	return true;
}
int main(){
	while (resuelve());
	return 0;
}