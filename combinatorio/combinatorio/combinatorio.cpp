#include <iostream>
using namespace std;
int comBiGenAux(int v[], const int &aFija, const int &bFija, const int & a, const int &b){
	int pos = (aFija - a)*(bFija + 1) + b;
	if (v[pos] != -1){
		return v[pos];
	}
	else{
		v[pos] = (comBiGenAux(v, aFija, bFija, a - 1, b - 1) + comBiGenAux(v, aFija, bFija, a - 1, b)) % 1000007;
		return v[pos];
	}

}
int combiGen(const int &aFija, const int &bFija){
	
	int v[10000];
	int pos = 0;
	for (int a = aFija; a >= 0; a--){
		for (int b = 0; b <= bFija; b++){
			if (a == b || b == 0)
				v[pos] = 1;
			else if (b == 1)
				v[pos] = a;
			else
				v[pos] = -1;
			pos++;
		}
				
	}
	return comBiGenAux(v, aFija, bFija, aFija, bFija);

}
void resuelve(){
	int a, b;
	cin >> a >> b;
	cout << combiGen(a, b) << endl;
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
	return 0;
}