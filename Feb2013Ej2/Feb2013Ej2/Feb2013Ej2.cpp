#include <iostream>
using namespace std;
void histogramaAux(int v[], int w[], int numElems, int n, int suma){
	if (n == numElems - 1)
		w[n] = v[n] + suma;
	else{
		w[n] = v[n] + suma;
		histogramaAux(v, w, numElems, n + 1, suma + v[n]);
	}
}
void resuelve(){
	int n;
	int v[1000];
	int w[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	if (n > 0){
		histogramaAux(v, w, n, 0, 0);
		for (int j = 0; j < n; j++)
			cout << w[j] << " ";
		cout << endl;
	}
}
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelve();
}