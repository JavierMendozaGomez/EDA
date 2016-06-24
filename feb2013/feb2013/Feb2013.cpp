#include <iostream>
#include <windows.h>
using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}
void histogramaLineal(int v[], int res[], int n){
	int suma = 0;
	for (int i = 0; i < n; i++){
		suma += v[i];
		res[i] = suma;
	}
}
void histogramaAux(int v[], int indice, int n, int res [],int &suma){
	if (indice <= n - 1){
		if (indice == n - 1){
			suma += v[indice];
			res[indice] = suma;
		}
		else{
			suma += v[indice];
			res[indice] = suma;
			histogramaAux(v, indice+1, n, res, suma);
		}
	}

}
void histograma(int v[], int n, int res[]){
	int suma = 0;
	int indice = 0;
	histogramaAux(v, indice, n, res,suma);
}
void imprimeHistograma(int res[], int n){
	for (int i = 0; i < n; i++)
		cout << res[i] << ",";
	cout << endl;
}
bool resuelve(){
	int n;
	cin >> n;
	if (n == -1)
		return false;
	int v[100];
	int res[100];
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	StartCounter();
	histograma(v, n, res);
	cout << GetCounter() << "\n";
	imprimeHistograma(res, n);

	return true;
}
bool resuelveLineal(){
	int n;
	cin >> n;
	if (n == -1)
		return false;
	int v[100];
	int res[100];
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	StartCounter();
	histogramaLineal(v,res,n);
	cout << GetCounter() << "\n";
	imprimeHistograma(res, n);
}
int main(){
	StartCounter();	
	while (resuelve ());
	return 0;
}