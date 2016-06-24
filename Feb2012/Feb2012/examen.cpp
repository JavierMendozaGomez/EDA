#include <iostream>
using namespace std;
void coincidentesDyVAux(int v[], const int &a, const int &b, bool & existe, int &p){
	if (b - a + 1 == 1){
		if (v[a] == a){
			existe = true;
			p = a;
		}
		else
			existe = false;
	}
	else{
		int m = (b + a) / 2;
		coincidentesDyVAux(v, a, m, existe, p);
		if (!existe)
			coincidentesDyVAux(v, m + 1, b, existe, p);
	}
}
void coincidentesDyV(int v[], const int &n,bool &existe, int &p){
	if (n == 0)
		existe = false;
	else {
		int a = 0;
		coincidentesDyVAux(v, a, n-1, existe, p);
	}
}	
bool resuelve(){
	int n,p;
	bool existe;
	cin >> n;
	if (n == -1)
		return false;
	int v[1000];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	coincidentesDyV(v, n,existe,p);
	if (existe)
		cout << "Si " << p << endl;
	else
		cout << "No" << endl;
	return true;
}
int main(){
	while (resuelve());
	return 0;
}