#include <iostream>
using namespace std;
void mayorVidente( int v[], const int &n, bool &existe, int &p){
	existe = false;
	int suma = 0;
	int k = n-1;
	while (k >= 0 && !existe){
		if (suma == v[k]){
			existe = true;
			p = k;
		}
		suma += v[k];
		k--;
	}
}



void resuelve()
{
	bool existe;
	int nElems,p;
	cin >> nElems;
	int v[10000];
	for (int i = 0; i<nElems; i++)
	{
		cin >> v[i];
	};
	mayorVidente(v, nElems, existe, p);
	if (existe)
		cout << "Si " << p << endl;
	else
		cout << "No" << endl;

}

int main() {
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i<nCasos; i++) {
		resuelve();
	}

	return 0;
}